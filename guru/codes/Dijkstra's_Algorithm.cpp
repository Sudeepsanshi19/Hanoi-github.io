#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define inf INT_MAX / 2

class Dijkstra {
public:
    int vertices;
    vector<int> dist, path, vis;
    int src, re;
    vector<vector<int> > cost;

    void read() {
        cost.resize(vertices, vector<int>(vertices, inf));
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
            cost[u][v] = w;
        }
    }

    void init() {
        vis.resize(vertices, 0);
        cout << "Enter the source: ";
        cin >> src;
        vis[src] = 1;

        path.resize(vertices, src);
        dist.resize(vertices);

        for (int i = 0; i < vertices; i++) {
            dist[i] = cost[src][i];
        }
        re = src;
    }

    void shortest_path() {
        for (int count = 0; count < vertices - 1; count++) {
            int minDist = inf, u = -1;

            for (int i = 0; i < vertices; i++) {
                if (!vis[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            vis[u] = 1;

            for (int v = 0; v < vertices; v++) {
                if (!vis[v] && cost[u][v] != inf && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    void print_distances() {
        for (int i = 0; i < vertices; i++) {
            cout << "Distance from " << src << " to " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    Dijkstra d;
    cout << "Enter the no. of vertices: ";
    cin >> d.vertices;
    d.read();
    d.init();
    d.shortest_path();
    d.print_distances();
    return 0;
}
