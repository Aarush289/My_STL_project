
# examples/Makefile
```makefile
# Simple Makefile for examples
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic
INCLUDE := -I../include

EXES := vector_example stack_example queue_example deque_example priority_queue_example map_example all_examples
# Optional examples (won't fail the whole build if they don't compile)
OPT_EXES := string_example set_example

all: $(EXES) opt

opt: $(OPT_EXES)

# Pattern rules
%_example: %_example.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@ || true

all_examples: all_examples.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(EXES) $(OPT_EXES)
