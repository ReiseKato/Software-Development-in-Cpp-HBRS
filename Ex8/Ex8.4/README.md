Modify function `isPatch` to operate on/with standard library containers instead of arrays.

## Goal

Replace:
```cpp
bool isPatch(const Triangle<Coord>** triangles, std::size_t size);
```

With:
```cpp
bool isPatch(const std::vector<Triangle<Coord>*>& triangles);
```

# Solution

| Step                                             | What it does                                                      |
| ------------------------------------------------ | ----------------------------------------------------------------- |
| `connected`                                      | Keeps track of triangles already identified as part of the patch  |
| `nextToAnalyze`                                  | Index of the triangle in `connected` we're checking neighbors for |
| `connectedCount`                                 | How many unique triangles we've discovered                        |
| `isAdjacent`                                     | Checks whether two triangles share 2 points                       |
| **Loop until** `nextToAnalyze == connectedCount` | Means we’ve explored all reachable triangles                      |

## Advantages of using std::vector

- Automatic memory management — no need for new/delete
- Safer and clearer to read
- Easy to resize or iterate using range-based loops