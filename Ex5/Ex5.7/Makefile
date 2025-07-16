NAME=Vector2D # Target executable name
CXX=g++ # C++ compiler
LNK=g++ # Linker
CXXFLAGS=-c -Wall # Compiler flags
LNKFLAGS= # Linker flags

# Object file directory
OBJDIR = obj
VECTORDIR = $(OBJDIR)/linalg

# All object files
OBJS = $(OBJDIR)/Vector2DMain.o $(VECTORDIR)/Vector2D.o $(VECTORDIR)/Vector3D.o $(VECTORDIR)/Rational.o $(VECTORDIR)/Complex.o $(VECTORDIR)/VectorUtil.o

.PHONY: default clean # Targets that are not files
default: $(NAME) # build the default target --> build the executable
clean:
	rm -rf $(NAME) $(OBJDIR)

# Create the directory for object files if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(VECTORDIR):
	mkdir -p $(VECTORDIR)

# Compile Vector2D.cc to obj/linalg/Vector2D.o
$(VECTORDIR)/Vector2D.o: linalg/Vector2D.cc linalg/Vector2D.hh | $(VECTORDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

$(VECTORDIR)/Vector3D.o: linalg/Vector3D.cc linalg/Vector3D.hh | $(VECTORDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

$(VECTORDIR)/VectorUtil.o: linalg/VectorUtil.cc linalg/VectorUtil.hh | $(VECTORDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

$(VECTORDIR)/Rational.o: linalg/Rational.cc linalg/Rational.hh | $(VECTORDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

$(VECTORDIR)/Complex.o: linalg/Complex.cc linalg/Complex.hh | $(VECTORDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

# Compile Vector2DMain.cc to obj/Vector2DMain.o
$(OBJDIR)/Vector2DMain.o: Vector2DMain.cc linalg/Vector2D.hh linalg/Rational.hh linalg/Complex.hh | $(OBJDIR)
	$(CXX) -o $@ $(CXXFLAGS) $<

# Link the object files to create the executable
$(NAME): $(OBJS)
	$(LNK) -o $@ $(LNKFLAGS) $(OBJS)

