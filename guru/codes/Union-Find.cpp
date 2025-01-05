
#include <iostream>
using namespace std;

int find(int arr[], int u, int v)
 {
    if (arr[u] == arr[v])
        return 1;
    else
        return 0;
}

void unionn(int arr[], int n, int u, int v)
{
    int temp = arr[u];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == temp)
            arr[i] = arr[v];
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    int choice, u, v;
    do {
        cout << "\n1. Union\n2. Find\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter elements to union: ";
            cin >> u >> v;
            unionn(arr, n, u, v);
            cout << "Union performed.\n";
            break;
        case 2:
            cout << "Enter elements to find: ";
            cin >> u >> v;
            if (find(arr, u, v))
                cout << "Connected.\n";
            else
                cout << "Not connected.\n";
            break;
        case 3:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
    while (choice != 3);
    return 0;
}
