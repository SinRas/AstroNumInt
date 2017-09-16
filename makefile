###########################################
################ Undone!!! ################
###########################################

# Compilers
NVCC=nvcc
GPP=g++
GCC=gcc
# Compiler Flags
NVCC_FLAGS=-G -g -O0 --compile --relocatable-device-code=false -gencode arch=compute_52,code=compute_52 -gencode arch=compute_52,code=sm_52  -x cu
GPP_FLAGS=
GCC_FLAGS=
###
NVCC_LDFLAGS=--cudart static --relocatable-device-code=false -gencode arch=compute_52,code=compute_52 -gencode arch=compute_52,code=sm_52 -link
GPP_LDFLAGS=
GCC_LDFLAGS=

# Source Files
## Main Program Files
SOURCES_MAIN=main.cpp
SOURCES_MAIN_GPU=main_gpu.cpp
## Common Functions
SOURCES_FUNCTIONS=$(wildcard ./functions/*.cpp)
## Kernels
SOURCES_KERNELS=$(wildcard ./kernels/*.cpp)
SOURCES_KERNELS_GPU=$(wildcard ./kernels/*.cu)

# Object files to Compile
## Common Files
OBJECTS_FUNCTIONS=$(SOURCES_FUNCTIONS:.cpp=.o)
## Object Kernels
OBJECTS_KERNELS=$(SOURCES_KERNELS:.cpp=.o)
OBJECTS_KERNELS_GPU=$(SOURCES_KERNELS_GPU:.cu=_cu.o)

# Name of the Executable file
EXECUTABLE=run_cpu

# Default Command (CPU)
all: cpu

# Compile (CPU)
cpu: $(SOURCES) $(EXECUTABLE)

# Make and Execute (CPU)
exec_cpu: all
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
