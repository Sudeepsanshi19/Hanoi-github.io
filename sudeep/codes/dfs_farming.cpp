#include <iostream>
#include <stdlib.h>
using namespace std;

int visited[6] = {0, 0, 0, 0, 0, 0}; 
int A[6][6] = {                 
    {0, 1, 1, 1, 1}, // Rooftop Garden connections
    {1, 0, 0, 0, 1},// Vertical Farm connections
    {1, 0, 0, 1, 0}, // Hydroponic Facility connections
    {1, 0, 1, 0, 1}, // Urban Greenhouse connections
    {1, 1, 0, 1, 0}  // Backyard Farm connections
};

string locations[5] = {
    "Rooftop Garden",
    "Vertical Farm",
    "Hydroponic Facility",
    "Urban Greenhouse",
    "Backyard Farm"
};

void DFS(int i) {
    cout << locations[i] << "\t";  
    visited[i] = 1;

    for (int j = 0; j < 6; j++) { 
        if (A[i][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    int start;

    cout << "Enter the starting location number (1 to 6): ";
    cin >> start;

    if (start < 1 || start > 5) {
        cout << "Invalid location! Please enter a number between 1 and 5.\n";
        return 1;
    }

    cout << "DFS traversal starting from location: " << locations[start - 1] << endl;
    DFS(start - 1); 

    return 0;
}
