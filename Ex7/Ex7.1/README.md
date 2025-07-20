A triangle is given by 3 vectors that describe its corner points.

Implement a Triangle class by 3 pointers to Vector2D-Objects, which get passed to the constructor.
Member functions point0, point1, and point2 return references to the 3 vectors. (Why references here, but pointer arguments in the constructor?)

Similarly as you did for vectors by using Coord, make your implementation largely independent of the choice of vector type. Provide the following global functions:

- `isConnected`, `isAdjacent`, `isEqual` take a reference to two triangles and return whether the two triangles share (at least) one, two, or three corners, respectively. 
    
    **Note**: „Sharing“ means that the Vector2D objects should be identical, not just equal.
- `isPatch` takes an array of pointers to triangles (why not array of triangles or of references?), given by a pointer to the beginning of the array and a std::size_t value that indicates its length. The function returns whether each triangle is adjacent to any (at least one) other triangle.
- `area` computes the area of a triangle by means of vector functions. To start, you determine vectors that describe two of the 3 sides, as $s_{1,2} = c_2 - c_1$ and $s_{1,3} = c_3 - c_1$ (where $c_i$ for $i = 1, 2, 3$ are the corner vectors).

    In 2D, the value of the determinant $|s1,2 s1,3| = s_{1,2_x} \cdot s_{1,3_y} - s_{1,2_y} \cdot s_{1,3_x}$ is two times the area of the triangle.

How would you design a data structure to store a large patch of triangles?


# Solution

## Why use pointers in constructor?

The triangle does not own these vector points. It only refery to existing vector instances. It is possible that multiple triangles are sharing the same point.

## Why return references from accessors?

To allow read/write to the original `Vector2D` objects. Like dereferencing the pointer.

## Why no .cc-file?

It's template code. So all definitions have to go into the header. Templated are only compiled when instantiated (i.e. when used with a specific type like `double`, `Rational`, or `Complex`). So the compiler must see the full definition when compiling ny file that uses template.

## Sicne `Vector2D` is not a template...

Since `Vecto2D` is not a template (only using `Complex`), code like Vector2D<Coord> is not goind to work, as the type is wrong.

## Why is this solution template code?

I read the task wrong and thought, that it needs to take any type, not only `Vector2D`. Well, it works with `Vector2D`, so it's fine. :)