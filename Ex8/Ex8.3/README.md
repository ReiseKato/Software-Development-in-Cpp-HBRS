Write a global function `isPatch` that takes as arguments (a pointer to) an array of pointers to `Triangle` objects and the length of the array.

The function checks and returns (as a boolean value) whether all triangles form a connected area, which is the case if:

- each triangle is adjacent to (i.e. shares a side with) at least one other triangle (--> use the function `isAdjacent`)
- the graph defined by the adjacencies (triangles as vertices, common sides as edges) is connected

Implement the function in the following way:

- allocate a second, auxiliary array where all (pointers to) triangles will be stored that have been identified as being part of the connected area – initially, all pointers in the array are `nullptr`
- copy one pointer from the original array into the first position of the aux. array – it forms a connected area
- store the offset (in the aux. array) of the next triangle to analyze for adjacencies – i.e. 0, initially
- search in the original array for other triangles that are adjacent to that triangle and add them to the aux. array if they are not in that array yet(!) – you need to store another offset that marks the position up to which the aux. array has been filled with adjacent triangles, which are yet to be analyzed
- proceed to the next triangle in the array and repeat the analysis
- stop when there is no other triangle in the array to analyze
- if (and only if) at this point the end of the array has been reached, all triangles belong to the connected area
- deallocate the auxiliary array

# Solution

## Parameters

```cpp
bool isPatch(const Triangle<Coord>** triangles, std::size_t size)
```

- `triangles` is an array of pointers to triangle objects.
- `size` is the number of triangles in the array.

## Idea

We are modeling a graph where:

- **Vertices** = triangles
- **Edges** = shared sides between triangles (i.e., adjacency)

We are performing a graph traversal (like BFS/DFS) to check if all triangles are reachable from the first one using only shared sides.

## Intertial Array `visited`

We use a temporary array `visited` of the same size:

- It tracks triangles we've found to be part of the connected patch.
- Initially all values are `nullptr`.

```cpp
const Triangle<Coord>** visited = new const Triangle<Coord>*[size];
```

## Initialization

```cpp
visited[0] = triangles[0];
visitedCount = 1;
current = 0;
```

Start by assuming the first triangle is in the connected patch.

## While Loop

```cpp
while (current < visitedCount)
```

- Loops over every triangle already identified as connected
- Tries to find more triangles that are adjacent and adds them to visited

This is very similar to a breadth-first search (BFS) on the graph of triangle adjacencies.

## Check Duplicates

```cpp
bool alreadyVisited = false;
for (...) {
    if (visited[j] == candidate) ...
}
```

We must avoid adding the same triangle twice to `visited`.

## Check full Connectivity

```cpp
bool result = (visitedCount == size);
```

If every triangle was discovered through adjacency, the patch is connected.

## Cleanup

We used `new[]`, so we must `delete[]` to prevent memory leaks (new allocates memory on the Heap. Stack gets freed automatically (End of Scope), but Heap does not!):

```cpp
delete[] visited;
```



