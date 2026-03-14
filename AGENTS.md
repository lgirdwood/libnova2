# Agent Instructions for Libnova

## Building and Testing

### C Code

Libnova uses CMake for building the C library.

**Building:**

```bash
# The build directory must always be outside the source directory
cmake -S . -B ../build -DCMAKE_BUILD_TYPE=Release
cmake --build ../build --config Release
```

**Testing:**
Tests are executed using CTest.

```bash
cd ../build
ctest -C Release
```

### Python Code

Python unit tests test the python bindings using the locally built library.

**Testing:**
Run the provided helper script in the `python` directory to discover and run all Python tests:

```bash
cd python
./run_tests.sh
```

*(This script automatically sets up the `LD_LIBRARY_PATH` and `PYTHONPATH` correctly relative to the build directory before running `python3 -m unittest discover tests`.)*

## Commit Message Guidelines

When making commits, ensure you strictly follow these rules:

- **Line Length**: The overall commit message must be at most 80 characters per line.
- **Subject**: The subject line must follow the format `feature: description`.
- **Body**: The commit message body must properly describe the change and why it was made.
- **Sign-off**: Every commit must include a sign-off line using the developer's name and email configured in git (e.g., retrieve via `git config user.name` and `git config user.email`).

### Example Commit Message

```text
core: fix memory leak in calculation layer

This change resolves an issue where memory allocated for the temporary
trajectory nodes was never freed. It ensures that the cleanup function
is always called before exiting the scope.

Signed-off-by: Developer Name <developer@example.com>
```
