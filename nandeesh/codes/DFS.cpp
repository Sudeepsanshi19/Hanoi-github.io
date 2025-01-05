#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, graph, visited);
        }
    }
}

void DFS(vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    DFSUtil(start, graph, visited);
}

int main() {
    vector<vector<int>> graph = {
        {},         // Node 0 (not used)
        {2, 3, 4},  // Node 1
        {1, 5},     // Node 2
        {1, 6},     // Node 3
        {1},        // Node 4
        {2},        // Node 5
        {3}         // Node 6
    };
    DFS(graph, 1);
    return 0;
}
