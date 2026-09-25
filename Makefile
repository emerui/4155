CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -O3

TARGETS = src/arrayMax src/prefixSum src/matrixMult src/mergeSort src/bfs

all: $(TARGETS)

src/arrayMax: src/arrayMax.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/prefixSum-O0: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O0 $< -o $@

src/prefixSum-O2: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O2 $< -o $@

src/prefixSum-O3: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) -O3 $< -o $@

src/matrixMult: src/matrixMult.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/mergeSort: src/mergeSort.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/bfs: src/bfs.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean