#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXSIZE 10

void readGraph(int graph[10][10], int v);
void displayGraph(int graph[10][10], int v);
void BFS(int graph[10][10], int v, int start);
void readGraph(int graph[10][10],int v)
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<"is there any edge from"<<i<<"to"<<j<<endl;
            cin>>graph[i][j];
        }
    }
}
void displayGraph(int graph[10][10],int v)
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<graph[i][j];

        }
        cout<<endl;
    }
}

// Queue implementation
int arr[MAXSIZE];
int Front = 0;
int Rear = -1;

bool isEmpty() {
    return Front == Rear + 1;
}

bool isfull() {
    return Rear == MAXSIZE - 1;
}

void Enqueue(int x) {
    if (isfull()) {
        cout << "Queue overflow" << endl;
    } else {
        Rear++;
        arr[Rear] = x;
    }
}

int Dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return -1; // Return a dummy value to indicate underflow
    } else {
        int x = arr[Front];
        Front++;
        return x;
    }
}

void BFS(int graph[10][10], int v, int start) {
    int visited[10] = {0};

    Enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int u = Dequeue();
        cout << u << " ";

        for (int i = 0; i < v; i++) {
            if (graph[u][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                Enqueue(i);
            }
        }
    }
}

int main() {
    int graph[10][10];
    int v, start;
    cout << "enter v" << endl;
    cin >> v;

    readGraph(graph, v);
    displayGraph(graph, v);
    cout << "enter start" << endl;
    cin >> start;

    BFS(graph, v, start);
}
