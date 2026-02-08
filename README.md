# libnova

**libnova** is a general purpose, double precision, Celestial Mechanics, Astrometry and Astrodynamics library.

## Features

- Precision of 1 arc second or better.
- Solar system ephemerides (Sun, Moon, Planets, Pluto).
- Aberration, nutation, precession, proper motion.
- Asteroids and Comets.
- Time conversions (Julian Day, Sidereal Time, Dynamical Time).
- Coordinate transformations (Equatorial, Ecliptic, Horizontal, Galactic).
- Rise, Set and Transit calculation.

## Requirements

- C compiler (GCC, Clang, MSVC)
- CMake (3.25 or later)
- Doxygen (optional, for documentation)

## Building

libnova uses **CMake** for its build system.

1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Configure the project:
   ```bash
   cmake ..
   ```
   
   Options:
   - `-DBUILD_SHARED_LIBS=ON` (default): Build shared libraries. Set to `OFF` for static libraries.

3. Build the library:
   ```bash
   cmake --build .
   ```

## Installation

To install the library and headers (requires permissions):

```bash
cmake --install .
```

Default installation prefix is `/usr/local` on Linux. You can change this during configuration:
```bash
cmake .. -DCMAKE_INSTALL_PREFIX=/custom/path
```

## Running Tests

Unit tests are built by default. To run the tests:

```bash
cd build
ctest --output-on-failure
```

Or run the test executable directly for verbose output:
```bash
./lntest/libnova_test_exec
```

## Documentation

To generate the API documentation (requires Doxygen):

```bash
cd build
cmake --build . --target doc
```

The documentation will be generated in `doc/html/index.html`.

## Usage

Include the main header in your C code:

```c
#include <libnova/libnova.h>
```

Link against the `nova` library (`-lnova`).

See `examples/` directory for usage examples (if available) or check `lntest/test.c` for comprehensive usage of API functions.
