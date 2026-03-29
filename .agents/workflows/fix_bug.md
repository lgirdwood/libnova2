---
description: How to debug and fix a reported issue
---

# Fixing a Bug (Test-Driven)

When the user gives you a bug report or you discover anomalous behavior, you must follow this test-driven workflow:

1. **Reproduce the Bug**: Write a failing unit test (in C or Python, depending on the bug's context). The test should isolate the faulty logic and successfully compile, but fail when run.
2. **Verify Failure**: Run the test suite to ensure the new test correctly reproduces the failure.
3. **Implement the Fix**: Modify the underlying C library or Python binding source code to fix the root cause of the bug.
4. **Verify the Fix**: Re-run the entire test suite (`ctest` for C, `./run_tests.sh` for Python). **100% of the tests must pass**, including your newly devised bug replication test.
5. **Iterate if Necessary**: If any tests fail (or a memory leak is introduced), debug and fix the implementation until all tests pass successfully.
6. **Clean Workspace**: Check `git status` and manually remove any generated test artifacts that shouldn't be committed.
7. **Commit Changes**: Once all tests pass, and the workspace is clean, you must ALWAYS ask the user for permission before executing any `git commit` commands.
