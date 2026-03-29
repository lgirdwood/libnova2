---
description: How to document C APIs using Doxygen
---

# Documenting C APIs (Doxygen)

When adding or modifying public functions, structs, or enums in C header (`.h`) files, you must ensure the API is fully documented:

1. **Write Doxygen Blocks**: Ensure every new public symbol has a Doxygen-style comment block (`/** ... */`) directly above it.
2. **Format Guidelines**:
   *   Use `@brief` or `\brief` for a short summary of the function.
   *   Use `@param` or `\param` for each parameter, explaining its purpose and any constraints (e.g., cannot be NULL).
   *   Use `@return` or `\return` to explain the return values and any error codes.
3. **Internal vs Public**: Only public-facing header files in `src/` should be documented like this. Internal static structs or C functions don't explicitly require Doxygen (though descriptive inline comments are always welcome).
4. **Auto-Format**: Run `clang-format` on the modified `.h` file (as per the C code changes workflow) to ensure the comment block is styled consistently with the rest of the codebase.
5. **Testing**: Modifications to header comments should not break the build. Ensure you run the `ctest` command in your build directory to verify everything cleanly compiles before committing.
