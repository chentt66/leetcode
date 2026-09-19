---
name: dsa-review
description: Review DSA practice code. If files are specified as arguments, review those. Otherwise, review all files changed today.
trigger: user-invocable
---

Review DSA practice code. If specific files are provided as arguments, review those. Otherwise, find and review all files changed today (excluding .git internals).

## Steps

1. **Determine files to review:**
   - If `$ARGUMENTS` is non-empty, treat it as a space-separated list of file paths to review.
   - Otherwise, run: `find . -type f -newermt "$(date '+%Y-%m-%d') 00:00:00" ! -path "*/.git/*"` to get today's changed files.

2. **Read each file.**

3. **For each file, comment on:**
   - Correctness of the algorithm
   - Time and space complexity (confirm or correct any stated complexity)
   - Code style and idiomatic usage for the language
   - Any subtle bugs or edge cases (e.g. empty input, single element, overflow)
   - Quality of inline comments — are they explaining the *why*, not just the what?

Keep feedback concise and specific. Point to line numbers where relevant.
