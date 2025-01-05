#include <iostream>
#include <cstdlib>
using namespace std;

/*void readGraph(int graph[10][10],int v)
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
void _DFS(int graph[10][10],int v,int start,int visited[])
{
    visited[start]=1;
    cout<<start;
    int i;
    for(i=0;i<v;i++)
    {
        if(graph[start][i]==1&&visited[i]==0)
        {
            _DFS(graph,v,i,visited);
        }
    }
}

void DFS(int graph[10][10],int v,int start)
{
    int visited[10]={0};
    _DFS(graph,v,start,visited);
}




int main()
{
    int graph[10][10];
    int v,start;
    cout<<"enter v"<<endl;
    cin>>v;

readGraph(graph,v);
displayGraph(graph,v);
    cout<<"enter start"<<endl;
    cin>>start;
DSF(graph,v,start);
}*/
#include <iostream>
#include <cstdlib>
using namespace std;

void readGraph(int graph[10][10],int v);
void displayGraph(int graph[10][10],int v);
void DFS(int graph[10][10],int v,int start);
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

void _DFS(int graph[10][10],int v,int start,int visited[])
{
    visited[start]=1;
    cout<<start;
    int i;
    for(i=0;i<v;i++)
    {
        if(graph[start][i]==1&&visited[i]==0)
        {
            _DFS(graph,v,i,visited);
        }
    }
}

void DFS(int graph[10][10],int v,int start)
{
    int visited[10]={0};
    _DFS(graph,v,start,visited);
}

int main()
{
    int graph[10][10];
    int v,start;
    cout<<"enter v"<<endl;
    cin>>v;

    readGraph(graph,v);
    displayGraph(graph,v);
    cout<<"enter start"<<endl;
    cin>>start;

    DFS(graph,v,start);
}
