#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Location {
    string name;
    int visits;
};

void Merge(const vector<Location> &B, const vector<Location> &C, vector<Location> &A) {
    int p = B.size();
    int q = C.size();
    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        if (B[i].visits >= C[j].visits) { // Sort in descending order
            A[k] = B[i];
            i++;
        } 
        else {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while (i < p) {
        A[k] = B[i];
        i++;
        k++;
    }
    while (j < q) {
        A[k] = C[j];
        j++;
        k++;
    }
}

void MergeSort(vector<Location> &A) {
    int n = A.size();
    
    if (n <= 1) {
        return;
    }

    int mid = n / 2;

    vector<Location> B(A.begin(), A.begin() + mid);
    vector<Location> C(A.begin() + mid, A.end());

    MergeSort(B);
    MergeSort(C);

    Merge(B, C, A);
}

int main() {
    vector<Location> locations = {
        {"Shani Deva Temple", 5000},
        {"Sunset Park", 3000},
        {"Summit Mountains", 7000},
        {"City Museum", 1500},
        {"Zoo/Aquarium", 4000},
        {"Forest Area", 6000},
        {"Crystal Lake", 4000},
        {"Historical Site", 500}
    };

    cout << "Original Locations and Visits: " << endl;
    for (const auto &loc : locations) {
        cout << loc.name << " - " << loc.visits << endl;
    }
    cout << endl;

    MergeSort(locations);

    cout << "Sorted Locations and Visits: " << endl;
    for (const auto &loc : locations) {
        cout << loc.name << " - " << loc.visits << endl;
    }
    cout << endl;

    return 0;
}
