#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
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
    BFS(graph, 1);
    return 0;
}
