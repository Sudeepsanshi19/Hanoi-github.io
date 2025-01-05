
#include <iostream>
#include <vector>
using namespace std;

struct Zone {
    string name;
    int visitors;
};

class segmentTree {
private:
    vector<int> tree;
    int n;

    void build_tree(vector<int>& data, int start, int end, int node) {
        if (start == end) {
            tree[node] = data[start];
        } 
        else {
            int mid = (start + end) / 2;
            build_tree(data, start, mid, 2 * node + 1);
            build_tree(data, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query_tree(int start, int end, int l, int r, int node) {
        if (start > r || end < l) return 0; 
        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int leftQuery = query_tree(start, mid, l, r, 2 * node + 1);
        int rightQuery = query_tree(mid + 1, end, l, r, 2 * node + 2);
        return leftQuery + rightQuery;
    }

    void updateTree(int start, int end, int index, int value, int node) {
        if (start == end) {
            tree[node] = value;
        } 
        else {
            int mid = (start + end) / 2;
            
            if (index <= mid) {
                updateTree(start, mid, index, value, 2 * node + 1);
            } 
            else {
                updateTree(mid + 1, end, index, value, 2 * node + 2);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    segmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build_tree(data, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return query_tree(0, n - 1, l, r, 0);
    }

    void update(int index, int value) {
        updateTree(0, n - 1, index, value, 0);
    }
};

int main() {
    vector<Zone> zones = {
        {"Zone 1", 50}, {"Zone 2", 20}, {"Zone 3", 30}, {"Zone 4", 40}, {"Zone 5", 10}, {"Zone 6", 60}
    };
    
    vector<int> visitor_data;
    for (const auto& zone : zones) {
        visitor_data.push_back(zone.visitors);
    }

    segmentTree segTree(visitor_data);

    cout << "Total visitors from zone 1 to 4: " << segTree.query(1, 4) << endl;
    segTree.update(3, 55); 
    cout << "Total visitors from zone 1 to 4 after update: " << segTree.query(1, 4) << endl;

    return 0;
}
