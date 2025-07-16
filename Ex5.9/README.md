# Vector2D Modular Project

## Description

This project demonstrates modular C++ design using a `Vector2D` class spread over header and source files. It reads a vector from input, adds it to itself, and outputs the result.

---

## Task

Create a Makefile for your latest version of the Vector 2D/3D example (involving Rational and Complex, if you have).

If you like (or if you dislike the length of your makefile), read about wildcards and string functions in the GNU make documentation

https://www.gnu.org/software/make/manual/html_node/Wildcards.html

https://www.gnu.org/software/make/manual/html_node/Text-Functions.html

and use them in your Makefile.

Extend the Makefile so that the command

`make pp`

creates preprocessor output for each source file and stores it in a directory pp. The directory should be subject to the clean target.

---

## Project Structure

```yaml
Vector2DProject/
├── linalg/
│ ├── Vector2D.hh # Vector2D class declaration
│ └── Vector2D.cc # Vector2D method and operator definitions
├── Vector2DMain.cc # Main function
├── Makefile # Build system
└── README.md # Documentation
```

---

## Manual Compilation

```bash
g++ -std=c++20 -c linalg/Vector2D.cc -o linalg/Vector2D.o
g++ -std=c++20 -c Vector2DMain.cc -o VectorMain.o
g++ -std=c++20 -o vector2D Vetor2DMain.o linalg/Vector2D.o
```

1. Complie every Soruce file
2. Link them all together
3. Execute

---

## Makefile

### Overview of Build Logic

The goal of the Makefile is to:

1. Compile .cc files into .o (object) files in the obj/ directory.

2. Link all .o files into a single executable called Vector2D.

3. Automatically create necessary directories if they don’t exist.

4. Provide a clean target to remove build artifacts.

### Breakdown

```makefile
NAME=Vector2D
```

- Sets the name of the final output program

```makefile
CXX = g++
LNK = g++
```

- `CXX`: used for compiling `.cc` files to `.o` files
- `LNK`: used for linking `.o` files into the final executable

```makefile
CXXFLAGS = -c -Wall
LNKFLAGS =
```

- `-c`: compile only (don't link yet)
- `Wall`: enable all warnings

```makefile
OBJDIR = obj
VECTORDIR = $(OBJDIR)/linalg
```

- Stores where compiled `.o` files should go

```makefile
OBJS = $(OBJDIR)/Vector2DMain.o $(VECTORDIR)/Vector2D.o
```

- The list of object files needed to build the final program

### Build Targets

1. `.PHONY`

```makefile
.PHONY=default clean
```

- Declares these targets as not real files - avoid conflicts (e.g. if a file is named clean or default)

2. `default`target

```makefile
default: $(NAME)
```

- The default rule when you just run `make`
- Depends on the final program target `Vector2D`

3. `clean` target

```makefile
clean:
    rm -rf $(NAME) $(OBJDIR)
```

- Deletes the executable and object directories

4. Directory creation targets

```makefile
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(VECTORDIR):
	@mkdir -p $(VECTORDIR)
```

- Ensures the object directories exist
- `@` hides command output

5. Compiling Vector2D.cc

```makefile
$(VECTORDIR)/Vector2D.o: linalg/Vector2D.cc linalg/Vector2D.hh | $(VECTORDIR)
    $(CXX) -o $@ $(CXXFLAGS) $<
```

- Builds `Vector2D.o` from `Vector2D.cc`.
- `| $(VECTORDIR)` means this rule also depends on the directory being present.
- `$@` is the output file (Vector2D.o).
- `$<` is the input file (Vector2D.cc).

6. Compiling Vector2DMain.cc

```makefile
$(OBJDIR)/Vector2DMain.o: Vector2DMain.cc linalg/Vector2D.hh | $(OBJDIR)
    $(CXX) -o $@ $(CXXFLAGS) $<
```

- Same structure as 5

7. Linking final executable

```makefile
$(NAME): $(OBJS)
    $(LNK) -o $@ $(LNKFLAGS) $(OBJS)
```

- Link all obejct files into the final executable
- `$@`is `Vector2D`
- `$(OBJS)` are all object files







