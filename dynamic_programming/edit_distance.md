## Edit Distance — DP Table & Summary

### Understand `dp[i][j]`


`dp[i][j]` = minimum operations to convert `word1[0..i-1]` → `word2[0..j-1]`

e.g.

`dp[i][0]`

= minimum edits (insert) from empty string to `word1[:i]`

`dp[0][j]`

= minimum edits (insert) from empty string to `word2[:j]`

= minimum edits (delete) from `word2[:j]` to empty string

`dp[i][j]` 

= minimum edits from `word1[:i]` to `word2[:j]`

= minimum edits from `word2[:j]` → `word1[:i]` |



**Recurrence:**

- If `word1[i-1] == word2[j-1]`: `dp[i][j] = dp[i-1][j-1]`
- Otherwise: `dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])`

| Op      | Index      | Meaning                      |
|---------|------------|------------------------------|
| replace | `i-1, j-1` | diagonal — substitute a char |
| insert  | `i,   j-1` | left — insert into word1     |
| remove  | `i-1, j`   | up — delete from word1       |

---

### DP Table (`word1 = "horse"`, `word2 = "rose"`)

|       |  "" |  r |  o |  s |  e |
|-------|----:|---:|---:|---:|---:|
|  ""   |   0 |  1 |  2 |  3 |  4 |
|  h    |   1 |  1 |  2 |  3 |  4 |
|  o    |   2 |  2 |  1 |  2 |  3 |
|  r    |   3 |  2 |  2 |  2 |  3 |
|  s    |   4 |  3 |  3 |  2 |  3 |
|  e    |   5 |  4 |  4 |  3 |  2 |

**Answer:** `dp[5][4] = 2`

Two optimal operations: **replace** `h → r`, then **remove** the extra `r`
(`horse → rorse → rose`)