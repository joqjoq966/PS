#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N,M;
string map[1001];
// bool visited[1001][1001]={false,};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int check[1001][1001][2];

int bfs(void) {
    queue<pair <pair<int, int>,int> > q; //y,x,벽뚫기(가능하면1, 아니면 0)
    q.push(make_pair(make_pair(0,0),1));
    // visited[b][a]=true;
    check[0][0][1]=1;

    while(!q.empty()) {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int wall = q.front().second;
        q.pop();

        if(y==N-1 && x==M-1) {
            return check[y][x][wall];
        }

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ny>=0 && nx>=0 && ny<N && nx<M) {
                if(map[ny][nx]=='1' && wall) {
                    check[ny][nx][wall-1]=check[y][x][wall]+1;
                    q.push(make_pair(make_pair(ny,nx),0));
                }
                else if(map[ny][nx]=='0' && check[ny][nx][wall]==0) {
                    check[ny][nx][wall]=check[y][x][wall]+1;
                    q.push(make_pair(make_pair(ny,nx),wall));

                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i=0;i<N;i++) {
        cin>>map[i];
    }

    int answer=bfs();
    // cout<<"\n";
    // cout<<check[N-1][M-1]+1;
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cout<<check[i][j][0];
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cout<<check[i][j][1];
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    cout<<answer;
    return 0;
}