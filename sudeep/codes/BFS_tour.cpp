#include<iostream>
#include<stdlib.h>
using namespace std;

struct Location {
    string name;
    int number;
};

Location locations[6] = {
    {"Summit Mountains", 1},
    {"Sunset Park", 2},
    {"Shani Deva Temple", 3},
    {"Zoo/Aquarium", 4},
    {"Crystal Lake", 5},
    {"Forest Area", 6}
};

int visited[6] = {0,0,0,0,0,0}; 
int A[6][6] = {
    {0,1,1,1,0,0},
    {1,0,0,0,1,1},
    {1,0,0,1,1,1},
    {1,0,1,0,0,0},
    {0,1,1,0,0,1},
    {0,1,1,0,1,0},
};

struct queue {
    int items[6];                               
    int front;
    int rear;
};

void initialise(struct queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct queue* q) {
    return (q->rear == -1);
}

void EnQueue(struct queue* q, int value) {
    if (q->rear == 5) {                             
        cout<<"Queue is full\n";
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int DeQueue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        cout<<"Queue is empty\n";
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(int start) {
    struct queue q;
    initialise(&q);
    
    visited[start] = 1;
    EnQueue(&q, start);

    cout << locations[start].name << "\t";

    while (!isEmpty(&q)) {
        int current = DeQueue(&q);
        
        for (int i = 0; i < 6; i++) {                      
            if (A[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                cout << locations[i].name << '\t';
                EnQueue(&q, i);
            }
        }
    }
}

int main() {
    int start;

    cout<<"Enter the starting vertex (1 to 6): "<<endl;            
    cin>>start;
    if (start < 1 || start > 6) {                            
        cout<<"Invalid vertex! Please enter a number between 1 and 6.\n";
        return 1;
    }

    cout<<"BFS traversal starting from location:\t"<<locations[start - 1].name<<endl;
    BFS(start - 1);

    return 0;
}
