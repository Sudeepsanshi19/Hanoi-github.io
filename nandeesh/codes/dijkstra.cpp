#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define INF INT_MAX / 2

class Dijkstra {
public:
    int vertices;
    vector<int> dist, path, vis;
    int src;
    vector<vector<int>> cost;

    // Read graph data
    void read() {
        cost.resize(vertices, vector<int>(vertices, INF));
        for (int i = 0; i < vertices; i++) {
            cost[i][i] = 0;
        }

        cout << "No. of edges: ";
        int edges;
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            cout << "u v w: ";
            int u, v, w;
            cin >> u >> v >> w;
            cost[u][v] = w;  // For directed graph, if undirected, also add cost[v][u] = w;
        }
    }

    // Initialize distances, paths, and visited status
    void init() {
        cout << "Enter the source: ";
        cin >> src;
        vis.resize(vertices, 0);
        dist.resize(vertices, INF);
        path.resize(vertices, -1); // path initialized to -1

        dist[src] = 0;  // Distance to the source is 0
    }

    // Dijkstra's algorithm to find the shortest path
    void shortest_path() {
        for (int count = 0; count < vertices - 1; count++) {
            int minDist = INF, u = -1;

            // Find the unvisited vertex with the smallest distance
            for (int i = 0; i < vertices; i++) {
                if (!vis[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            // If no vertex is reachable, break the loop
            if (u == -1) break;

            vis[u] = 1;  // Mark vertex u as visited

            // Update distances for neighboring vertices of u
            for (int v = 0; v < vertices; v++) {
                if (!vis[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    // Print distances from source to all vertices
    void print_distances() {
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INF) {
                cout << "Distance from " << src << " to " << i << ": INF (unreachable)" << endl;
            } else {
                cout << "Distance from " << src << " to " << i << ": " << dist[i] << endl;
            }
        }
    }
};

int main() {
    Dijkstra d;
    cout << "Enter the no. of vertices: ";
    cin >> d.vertices;

    d.read(); // Read the graph data (edges and weights)
    d.init(); // Initialize distances, paths, and source vertex
    d.shortest_path(); // Run Dijkstra's algorithm
    d.print_distances(); // Print the result
    
    return 0;
}
