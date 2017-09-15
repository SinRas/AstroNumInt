# Compiler
NVCC=nvcc
# Compiler Flags
NVCCFLAGS=-G -g -O0 --compile --relocatable-device-code=false -gencode arch=compute_52,code=compute_52 -gencode arch=compute_52,code=sm_52  -x cu
###
LDFLAGS=--cudart static --relocatable-device-code=false -gencode arch=compute_52,code=compute_52 -gencode arch=compute_52,code=sm_52 -link

# Source Files
SOURCES=main.cu

# Object files to Compile
OBJECTS=$(SOURCES:.cu=.o)

# Name of the Executable file
EXECUTABLE=main

# Default Command
all: $(SOURCES) $(EXECUTABLE)

# Make and Execute
exec: all
	./$(EXECUTABLE)

# Required Files
$(EXECUTABLE): $(OBJECTS)
	$(NVCC) $(LDFLAGS) $(OBJECTS) -o $@

# Compile .cu files to .o
$(OBJECTS): %.o: %.cu
	$(NVCC) $(NVCCFLAGS) $< -o $@

# Clean Files
clean:
	rm *~ *.o $(EXECUTABLE)
