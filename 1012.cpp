#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int T,M,N,K;
int map[51][51]={0,};
bool visited[51][51]={false,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void bfs(int b, int a) {
    queue<pair<int,int> > q;
    q.push(make_pair(b,a));
    visited[b][a]=true;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<M && ny<N && !visited[ny][nx] && map[ny][nx]==1) {
                visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    int cnt;
    while(T--) {
        memset(map,0,sizeof(int)*51*51);
        memset(visited,false,51*51);
        cin>>M>>N>>K;
        for(int i=0;i<K;i++) {
            int a, b;
            cin>>a>>b;
            map[b][a]=1;
        }
        cnt=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(map[i][j]==1 && !visited[i][j]) {
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}