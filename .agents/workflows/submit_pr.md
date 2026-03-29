---
description: How to submit a Pull Request
---

# Pull Request Submission

When a feature or fix is entirely complete and committed locally, you must follow this workflow to submit the changes as a Pull Request:

1. **Verify State**: Confirm all uncommitted changes have been cleaned up and ensure your branch has all the completed work in logical commits.
2. **Review Commit History**: Confirm your commit messages follow the repository guidelines (e.g., maximum 80 characters per line, `feature: description` format, and the required Signed-off-by trailer).
   * *If the commit history is messy, offer to rebase or squash the commits interactively before opening the PR.*
3. **Create the Pull Request**: Use the `gh` CLI (if available and authenticated) or the configured GitHub MCP tool to open the PR.
4. **Format the PR Description**:
   * Include a short summary of the problem or feature.
   * Link to any relevant issue numbers (e.g., `Fixes #123`).
   * Outline any major architectural decisions or new tests added.
5. **Await Review**: Once the PR is submitted, review the output. Wait for the user or CI to dictate next steps. Do not automatically attempt to merge the PR unless expressly asked by the user.
