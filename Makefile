CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -O3

TARGETS = src/arrayMax src/prefixSum src/matrixMult src/mergeSort src/bfs

all: $(TARGETS)

src/arrayMax: src/arrayMax.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/prefixSum: src/prefixSum.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/matrixMult: src/matrixMult.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/mergeSort: src/mergeSort.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

src/bfs: src/bfs.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean