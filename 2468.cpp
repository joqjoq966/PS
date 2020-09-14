#include<iostream>
#include<cstring>
using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(int x, int y) {
    visited[x][y]=true;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0|| nx>=N || ny>=N) {
            continue;
        }
        if(visited[nx][ny]==false && map[nx][ny]!=0) {
            dfs(nx,ny);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max_island=0,cnt=0;
    cin>>N;
    int max=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>map[i][j];
            if(max<map[i][j]) max=map[i][j];
        }
    }
    for(int i=1;i<max;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if(map[j][k]<=i) {
                    map[j][k]=0;
                }
            }
        }
        cnt=0;
        memset(visited,false,101*101);

        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if(visited[j][k]==0 && map[j][k]!=0) {
                    dfs(j,k);
                    cnt++;
                }
            }
        }
        //cout<<"i:"<<i<<" cnt:"<<cnt<<"\n";
        if(max_island<cnt) {
            max_island=cnt;
        }
    }
    if(max_island==0) cout<<1;
    else cout<<max_island;
    


    return 0;
}