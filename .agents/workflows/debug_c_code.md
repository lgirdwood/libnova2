---
description: How to debug C crashes or memory leaks
---

# Debugging C Code

When you encounter a segmentation fault, memory leak, or other native memory-related bug in the C library, use the following workflow:

1. **Build with AddressSanitizer (ASAN)**: Reconfigure CMake to build the library and tests with memory instrumentation so that crashes output clear stack traces.
   // turbo

   ```bash
   cmake -S . -B ../build_asan -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-fsanitize=address -g" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
   cmake --build ../build_asan
   ```

2. **Run the Failing Test**: Execute the specific failing test within the `build_asan` directory to get standard ASAN output detailing the exact line of the memory leak or invalid access.
3. **Analyze and Fix**: Analyze the ASAN stack trace, update your source changes, rebuild, and re-run until the error is resolved.
4. **Alternative - Valgrind**: If ASAN is unavailable or you are looking specifically for uninitialized memory reads, run the test interactively with valgrind:
   // turbo

   ```bash
   valgrind --leak-check=full --track-origins=yes ./path_to_test_executable
   ```

5. **Revert to Release Build**: Before committing, ensure you re-build in `Release` mode (as dictated in `AGENTS.md` build instructions) and verify that all C tests pass normally without sanitizers.
