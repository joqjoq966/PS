#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int N;
string apart[25];
bool visited[25][25]={false,};
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int bfs(int a, int b){
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    visited[a][b]=true;
    int cnt=0;

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<=N-1 && ny<=N-1 && apart[ny][nx]=='1' && visited[ny][nx]==false)
            {
                q.push(make_pair(ny,nx));
                visited[ny][nx]=true;
                apart[ny][nx]='0';
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>apart[i];

    int arr[100]={0,};
    int idx=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(apart[i][j]!='0')
            {
                arr[idx]=bfs(i,j);
                idx++;
            }
        }
    }
    cout<<idx<<"\n";
    sort(arr,arr+idx);
    for(int i=0;i<idx;i++)
    {
        cout<<arr[i]+1<<"\n";
    }
    

    return 0;
}