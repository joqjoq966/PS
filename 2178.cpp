#include<iostream>
#include<queue>
#include<string>

using namespace std;

int N,M;
string maze[100];
bool visited[100][100]={false,};
int check[100][100]={0,};
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
void bfs(int a, int b){
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    visited[a][b]=true;
    
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<=M-1 && ny<=N-1 && maze[ny][nx]=='1' && visited[ny][nx]==false)
            {
                visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
                check[ny][nx]=check[y][x]+1;
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>maze[i];
    }

    bfs(0,0);

    cout<<check[N-1][M-1]+1;
    

    return 0;
}