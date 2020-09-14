#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;

int N,M,V;
int graph[MAX][MAX];
bool visited[MAX];

void dfs(int v){
    
    cout<<v<<" ";

    visited[v]=true;
    for(int i=1;i<=N;i++)
    {
        if(graph[v][i] && visited[i]==false)
        {
            dfs(i);
        }
        if(i==N)
            return;
    }
}

void bfs(int v){

    visited[v]=true;
    
    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        v=q.front();
        cout<<v<<" ";
        q.pop();
        for(int i=1;i<=N;i++)
        {
            if(graph[v][i] && !visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>V;
    
    memset(graph,0,MAX*sizeof(int));
    memset(visited,false,MAX*sizeof(bool));

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    dfs(V);
    cout<<"\n";
    memset(visited,false,MAX*sizeof(bool));
    bfs(V);

    return 0;
}