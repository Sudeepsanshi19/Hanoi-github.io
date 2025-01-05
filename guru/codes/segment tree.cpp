#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build_tree(vector<int>& data, int start, int end, int node) {
        if (start == end) {
            tree[node] = data[start];
        } else {
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

    void update_tree(int start, int end, int index, int value, int node) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update_tree(start, mid, index, value, 2 * node + 1);
            } else {
                update_tree(mid + 1, end, index, value, 2 * node + 2);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build_tree(data, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return query_tree(0, n - 1, l, r, 0);
    }

    void update(int index, int value) {
        update_tree(0, n - 1, index, value, 0);
    }
};

int main() {
    vector<int> parkingSpaces = {50, 20, 30, 40, 10, 60};
    SegmentTree segTree(parkingSpaces);
    cout << "Total available spaces from Zone 2 to Zone 5: " << segTree.query(1, 4) << endl;
    segTree.update(3, 35);
    cout << "Total available spaces from Zone 2 to Zone 5 after update: " << segTree.query(1, 4) << endl;
    return 0;
}
