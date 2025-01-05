#include <iostream>
#include <vector>
#include <string>
#define inft 9999 // taking infinite as inft

using namespace std;

struct Location {
    string name;
    int number;
};


class Graph {
    private:
    vector<vector<int>> graph;
    int n;
    
    public:
    Graph(const vector<vector<int>>& matrix) : graph(matrix), n(matrix.size()) {}
    void floyds_algo();
    void display_path(const vector<vector<int>>& dist);
};

void Graph::floyds_algo() {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != inft && dist[k][j] != inft && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "Shortest distance matrix after applying Floyd-Warshall:" << endl;
    display_path(dist); 
}
void Graph::display_path(const vector<vector<int>>& dist) { 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == inft)
                cout << "inft" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    vector<Location> locations = {
        {"Summit Mountains", 0},
        {"Sunset Park", 1},
        {"Shani Deva Temple", 2},
        {"Zoo/Aquarium", 3},
        {"Crystal Lake", 4},
        {"Forest Area", 5}
    };

    vector<vector<int>> graph = {
        {0, 80, 40, inft, inft, inft},
        {inft, 0, 110, inft, 60, inft},
        {inft, inft, 0, 20, 40, inft},
        {inft, inft, inft, 0, inft, 30},
        {inft, inft, inft, inft, 0, 40},
        {40, inft, inft, inft, inft, 0}
    };

    Graph g(graph);
    cout << "Given user input graph with weights:" << endl;
    g.display_path(graph);
    cout << endl;

    g.floyds_algo();

    return 0;
}
