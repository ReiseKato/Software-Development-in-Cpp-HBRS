NAME=Vector2D # Target executable name
CXX=g++ # C++ compiler
LNK=g++ # Linker
CXXFLAGS=-c -Wall # Compiler flags
LNKFLAGS= # Linker flags

# Object file directory
OBJDIR = obj
VECTORDIR = $(OBJDIR)/linalg

# Preprocessor output directory
PPDIR = pp
PPVECTORDIR = $(PPDIR)/linalg

# List of SRC files
SRC = linalg/Vector2D.cc linalg/Vector3D.cc linalg/Rational.cc linalg/Complex.cc linalg/VectorUtil.cc Vector2DMain.cc

## List of preprocessor output files
PPFILES = $(SRC:%.cc=$(PPDIR)/%.ii)

# All object files
OBJS = $(OBJDIR)/Vector2DMain.o $(VECTORDIR)/Vector2D.o $(VECTORDIR)/Vector3D.o $(VECTORDIR)/Rational.o $(VECTORDIR)/Complex.o $(VECTORDIR)/VectorUtil.o
OBJS = $(SRC:%.cc=$(OBJDIR)/%.o)

.PHONY: default clean pp # Targets that are not files (pp: creates preprocessor output for each source file)
default: $(NAME) # build the default target --> build the executable
clean:
	rm -rf $(NAME) $(OBJDIR) $(PPDIR)

# Create the directory for object files and preprocessor files if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(VECTORDIR):
	mkdir -p $(VECTORDIR)

$(PPDIR):
	mkdir -p $(PPDIR)

$(PPVECTORDIR):
	mkdir -p $(PPVECTORDIR)

pp:	$(PPFILES) # Generate preprocessor output files

# Rule to generate preprocessor output files
$(PPDIR)/%.ii: %.cc | $(PPDIR) $(PPVECTORDIR)
	$(CXX) -E $< -o $@ 

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

