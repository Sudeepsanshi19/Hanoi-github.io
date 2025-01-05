#include<iostream>
#define MAX 100
using namespace std;

class Graph {
public:
    int numVertices;
    int costMatrix[MAX][MAX];

    Graph(int vertices);
    void inputGraph();
    void printGraph();
    void findShortestPaths();
    void displayShortestPaths();
};

Graph::Graph(int vertices) {
    numVertices = vertices;
}

void Graph::inputGraph() {
    cout << "Enter the cost matrix (use 999 for infinity)" << endl;
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            cin >> costMatrix[i][j];
        }
    }
}

void Graph::printGraph() {
    cout << "The cost matrix is:" << endl;
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            cout << costMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void Graph::findShortestPaths() {
    for (int k = 1; k <= numVertices; k++) {
        for (int i = 1; i <= numVertices; i++) {
            for (int j = 1; j <= numVertices; j++) {
                if (costMatrix[i][k] != 999 && costMatrix[k][j] != 999 && 
                    (costMatrix[i][k] + costMatrix[k][j] < costMatrix[i][j])) {
                    costMatrix[i][j] = costMatrix[i][k] + costMatrix[k][j];
                }
            }
        }
    }
}

void Graph::displayShortestPaths() {
    cout << "All pairs of shortest paths are as follows:" << endl;
    printGraph();
}

int main() {
    int vertices;
    cout << "Enter the number of vertices:" << endl;
    cin >> vertices;

    Graph g(vertices);
    g.inputGraph();
    g.printGraph();
    g.findShortestPaths();
    g.displayShortestPaths();
    
    return 0;
}
