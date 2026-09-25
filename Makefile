CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 

TARGETS = src/arrayMax src/matrixMult src/mergeSort src/bfs

all: $(TARGETS)

src/arrayMax: src/arrayMax.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

src/prefixSum-O0: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O0 $< -o $@

src/prefixSum-O2: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O2 $< -o $@

src/prefixSum-O3: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

src/matrixMult: src/matrixMult.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

src/mergeSort: src/mergeSort.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

src/bfs: src/bfs.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

clean:
	rm -f $(TARGETS) src/prefixSum-O0 src/prefixSum-O2 src/prefixSum-O3

.PHONY: all clean