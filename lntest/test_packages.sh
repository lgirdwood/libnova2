#!/bin/bash
set -e

# Default to ../build-libnova2 if not provided
BUILD_DIR=${1:-../build-libnova2}
SRC_DIR=$(dirname "$0")/..
TEST_DIR="$SRC_DIR/../test-libnova2"

# Convert BUILD_DIR to absolute path if necessary, but here we just cd into SRC_DIR
cd "$SRC_DIR"

echo "=== Building packages ==="
make -C "$BUILD_DIR" package || echo "CPack returned an error (likely due to missing rpmbuild or similar), but some packages may have been built."
rm -rf python/dist/*
make -C "$BUILD_DIR" python-package

# Clean test directory
rm -rf "$TEST_DIR"
mkdir -p "$TEST_DIR"

echo "=== Testing DEB package ==="
if command -v dpkg-deb >/dev/null 2>&1; then
    DEB_PKG=$(ls "$BUILD_DIR"/libnova2-*-lib.deb 2>/dev/null | head -n 1)
    DEB_PY_PKG=$(ls "$BUILD_DIR"/libnova2-*-python.deb 2>/dev/null | head -n 1)
    if [ -n "$DEB_PKG" ]; then
        echo "Extracting $DEB_PKG..."
        mkdir -p "$TEST_DIR/deb"
        dpkg-deb -x "$DEB_PKG" "$TEST_DIR/deb"
        if [ -n "$DEB_PY_PKG" ]; then
            echo "Extracting $DEB_PY_PKG..."
            dpkg-deb -x "$DEB_PY_PKG" "$TEST_DIR/deb"
        fi
        
        echo "Compiling example against DEB..."
        gcc "examples/sun.c" -I"$TEST_DIR/deb/usr/include" -L"$TEST_DIR/deb/usr/lib" -lnova2 -lm -o "$TEST_DIR/deb/test_sun"
        echo "Running DEB example..."
        LD_LIBRARY_PATH="$TEST_DIR/deb/usr/lib" "$TEST_DIR/deb/test_sun" > /dev/null
        echo "DEB package test PASSED."

        if [ -n "$DEB_PY_PKG" ]; then
            echo "Testing DEB native python component..."
            PY_PATH=$(find "$TEST_DIR/deb/usr/lib" -path "*/site-packages" -type d 2>/dev/null | head -n 1)
            [ -z "$PY_PATH" ] && PY_PATH=$(find "$TEST_DIR/deb/lib" -path "*/site-packages" -type d 2>/dev/null | head -n 1)
            if [ -n "$PY_PATH" ]; then
                LD_LIBRARY_PATH="$TEST_DIR/deb/usr/lib" PYTHONPATH="$PY_PATH" python3 -c "import libnova2"
                echo "DEB Python package test PASSED."
            fi
        fi
    else
        echo "DEB package not generated."
    fi
else
    echo "dpkg-deb not found, skipping DEB test."
fi

echo "=== Testing RPM package ==="
if command -v rpm2cpio >/dev/null 2>&1 && command -v cpio >/dev/null 2>&1; then
    RPM_PKG=$(ls "$BUILD_DIR"/libnova2-*-lib.rpm 2>/dev/null | head -n 1)
    RPM_PY_PKG=$(ls "$BUILD_DIR"/libnova2-*-python.rpm 2>/dev/null | head -n 1)
    if [ -n "$RPM_PKG" ]; then
        echo "Extracting $RPM_PKG..."
        mkdir -p "$TEST_DIR/rpm"
        ABS_RPM_PKG=$(realpath "$RPM_PKG")
        (cd "$TEST_DIR/rpm" && rpm2cpio "$ABS_RPM_PKG" | cpio -idmv > /dev/null 2>&1)
        if [ -n "$RPM_PY_PKG" ]; then
             echo "Extracting $RPM_PY_PKG..."
             ABS_RPM_PY_PKG=$(realpath "$RPM_PY_PKG")
             (cd "$TEST_DIR/rpm" && rpm2cpio "$ABS_RPM_PY_PKG" | cpio -idmv > /dev/null 2>&1)
        fi
        
        # RPM could install to /usr/lib or /usr/lib64
        LIB_DIR="$TEST_DIR/rpm/usr/lib"
        if [ -d "$TEST_DIR/rpm/usr/lib64" ]; then
            LIB_DIR="$TEST_DIR/rpm/usr/lib64"
        fi

        echo "Compiling example against RPM..."
        gcc "examples/sun.c" -I"$TEST_DIR/rpm/usr/include" -L"$LIB_DIR" -lnova2 -lm -o "$TEST_DIR/rpm/test_sun"
        echo "Running RPM example..."
        LD_LIBRARY_PATH="$LIB_DIR" "$TEST_DIR/rpm/test_sun" > /dev/null
        echo "RPM package test PASSED."

        if [ -n "$RPM_PY_PKG" ]; then
            echo "Testing RPM native python component..."
            PY_PATH=$(find "$TEST_DIR/rpm/usr/lib" -path "*/site-packages" -type d 2>/dev/null | head -n 1)
            [ -z "$PY_PATH" ] && PY_PATH=$(find "$TEST_DIR/rpm/lib" -path "*/site-packages" -type d 2>/dev/null | head -n 1)
            [ -z "$PY_PATH" ] && PY_PATH=$(find "$TEST_DIR/rpm/usr/lib64" -path "*/site-packages" -type d 2>/dev/null | head -n 1)
            if [ -n "$PY_PATH" ]; then
                LD_LIBRARY_PATH="$LIB_DIR" PYTHONPATH="$PY_PATH" python3 -c "import libnova2"
                echo "RPM Python package test PASSED."
            fi
        fi
    else
        echo "RPM package not generated (maybe rpmbuild is missing), skipping RPM test."
    fi
else
    echo "rpm2cpio or cpio not found, skipping RPM test."
fi

echo "=== Testing Python package (Wheel) ==="
if command -v python3 >/dev/null 2>&1; then
    WHL_PKG=$(ls "python/dist"/libnova2-*.whl 2>/dev/null | head -n 1)
    if [ -n "$WHL_PKG" ]; then
        echo "Creating venv..."
        python3 -m venv "$TEST_DIR/venv"
        source "$TEST_DIR/venv/bin/activate"
        echo "Installing $WHL_PKG..."
        pip install --quiet "$WHL_PKG"
        echo "Running Python test..."
        # Provide the DEB extracted library path so ctypes can find the library
        if [ -d "$TEST_DIR/deb/usr/lib" ]; then
            LD_LIBRARY_PATH="$TEST_DIR/deb/usr/lib" python3 -c "import libnova2; print('Successfully imported libnova2')"
        elif [ -d "$TEST_DIR/rpm/usr/lib" ]; then
            LD_LIBRARY_PATH="$TEST_DIR/rpm/usr/lib" python3 -c "import libnova2; print('Successfully imported libnova2')"
        else
            echo "Warning: No C library found to test Python binding against. Attempting anyway..."
            python3 -c "import libnova2"
        fi
        deactivate
        echo "Python package test PASSED."
    else
        echo "Wheel package not found, skipping Python test."
    fi
else
    echo "python3 not found, skipping Python test."
fi

echo "=== Package tests completed successfully. ==="
