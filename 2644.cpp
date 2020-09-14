#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[101];
int dist[101]={0,};
int bfs(int start, int end) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x==end) {
            return dist[end];
        }
        int size = v[x].size();

        for(int i=0;i<size;i++) {
            int y = v[x][i];
            if(dist[y]==0) {
                q.push(y);
                dist[y]=dist[x]+1;
            }
        }
    }
    return -1;
}
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b,m;
    cin>>n>>a>>b>>m;
    
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<bfs(a,b);

    return 0;
}