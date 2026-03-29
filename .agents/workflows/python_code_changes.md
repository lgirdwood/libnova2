---
description: How to modify Python code and tests
---

# Modifying Python Code

When making changes to Python source files (`.py`) in the `python/` directory, you must follow this workflow to ensure code quality and test coverage:

1. **Make Changes**: Edit the Python code or test files as required.
2. **Auto-Format**: Automatically format the modified Python files using `black` (if available in the environment).
   // turbo

   ```bash
   python3 -m black python/
   ```

3. **Run Python Tests**: You MUST run the Python tests using the provided helper script. It handles setting up `LD_LIBRARY_PATH` and `PYTHONPATH` relative to the local C build correctly.
   // turbo

   ```bash
   cd python && ./run_tests.sh
   ```

4. **Run C Tests**: Run the upstream C tests using `ctest` as well to verify the underlying library continues to perform correctly without regressions.
5. **Clean Workspace**: Check `git status` and run `git clean -fdx` or manually remove generated artifacts like `__pycache__` or `.egg-info` folders.
6. **Commit Changes**: You must ALWAYS ask the user for permission before running any `git commit` commands.
