#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void Kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<Edge> mst;
    int mstWeight = 0;

    for (Edge &edge : edges) {
        int srcParent = findParent(edge.src, parent);
        int destParent = findParent(edge.dest, parent);

        if (srcParent != destParent) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            parent[srcParent] = destParent;
        }
    }

    cout << "MST edges:\n";
    for (Edge &e : mst)
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    cout << "Total weight: " << mstWeight << endl;
}

int main() {
    int n = 4;  // Number of nodes
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Kruskal(n, edges);
    return 0;
}
