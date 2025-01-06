#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INFINITY INT_MAX


struct Edge {
    int u;  // Start vertex of the edge
    int v;  // End vertex of the edge
    int w;  // Weight of the edge (u,v)
};


struct Graph {
    int V;              // Total number of vertices in the graph
    int E;              // Total number of edges in the graph
    vector<Edge> edges; // Array of edges
};

void bellmanFord(Graph &g, int source);
void display(const vector<int> &arr);

int main() {
   
    Graph g;
    g.V = 4;  // Total vertices
    g.E = 5;  // Total edges

    
    g.edges = {
        {0, 1, 5},  // edge 0 --> 1
        {0, 2, 4},  // edge 0 --> 2
        {1, 3, 3},  // edge 1 --> 3
        {2, 1, 6},  // edge 2 --> 1
        {3, 2, 2}   // edge 3 --> 2
    };

    bellmanFord(g, 0); // 0 is the source vertex

    return 0;
}

void bellmanFord(Graph &g, int source) {
    int tV = g.V; // Total vertices in the graph
    int tE = g.E; // Total edges in the graph

    
    vector<int> d(tV, INFINITY);
    vector<int> p(tV, -1);

    
    d[source] = 0;

   
    for (int i = 1; i <= tV - 1; ++i) {
        for (int j = 0; j < tE; ++j) {
            int u = g.edges[j].u;
            int v = g.edges[j].v;
            int w = g.edges[j].w;

            if (d[u] != INFINITY && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

   
    for (int i = 0; i < tE; ++i) {
        int u = g.edges[i].u;
        int v = g.edges[i].v;
        int w = g.edges[i].w;

        if (d[u] != INFINITY && d[v] > d[u] + w) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

   
    cout << "Distance array: ";
    display(d);
    cout << "Predecessor array: ";
    display(p);
}

void display(const vector<int> &arr) {
    for (int val : arr) {
        if (val == INFINITY) {
            cout << "INF ";
        } else {
            cout << val << " ";
        }
    }
    cout << endl;
}
