#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
// i gave up ->-


struct graph_t {
    int n; /* vertices */
    long m; /* edges */
    std::vector<long> offsets; /* length n+1 */
    std::vector<int> adj; /* the neighbours of v are stored in */
    /* adj[offsets[v] .. offsets[v+1]-1] */
};
int main(){
    
}