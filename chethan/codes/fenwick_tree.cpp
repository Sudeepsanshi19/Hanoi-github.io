#include <iostream>
using namespace std;

// Fenwick Tree or Binary Indexed Tree (BIT)
int BIT[20], a[20], n;


void update(int x, int delta) {
    for (; x <= n; x += x & -x)
        BIT[x] += delta;
}


int query(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x)
        sum += BIT[x];
    return sum;
}

int main() {
    cin >> n; // Input size of the array
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        update(i, a[i]); 
    }

    cout << "The sum of the first 10 items is given by\n" << query(10) << endl;
    return 0;
}
