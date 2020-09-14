#include<iostream>
#include<vector>
using namespace std;

int com,net;
vector<int> virus[101];
bool visited[101]={false,};
int cnt=0;

void dfs(int a) {
    visited[a]=true;
    for(int i=0;i<virus[a].size();i++) {
        if(!visited[virus[a].at(i)]) {
            visited[virus[a].at(i)]=true;
            cnt++;
            dfs(virus[a].at(i));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>com>>net;
    for(int i=0;i<net;i++){
        int a, b;
        cin>>a>>b;
        virus[a].push_back(b);
        virus[b].push_back(a);
    }
    dfs(1);
    
    cout<<cnt;

    return 0;
}