#include<iostream>

using namespace std;

int R,C;
char map[22][22];
bool visited[22][22]={false,};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int arr[26]={0,};
int check[22][22]={0,};
int cnt=0,max_way=0;
int same_before(char a) {
    if(arr[a-'A']==1) {
        return 1;
    }
    return 0;
}
void dfs(int y, int x) {
    //cout<<x<<" "<<y;
    arr[map[y][x]-'A']=1;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=C ||ny>=R) 
            continue;
        if(!same_before(map[ny][nx])) {
            //cout<<"nx:"<<nx<<"ny:"<<ny;
            check[ny][nx]=check[y][x]+1;
            dfs(ny,nx);
        }
    }
    arr[map[y][x]-'A']=0;
    if(check[y][x]>max_way)
        max_way=check[y][x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>R>>C;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin>>map[i][j];
        }
    }
    dfs(0,0);
    cout<<max_way+1;

    return 0;

}