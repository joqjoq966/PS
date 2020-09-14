#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N,M;
int map[301][301];
int map2[301][301];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int decreasing[301][301]={0,};
bool visited[301][301]={false,};
int cnt=0,cnt2=0;
int adjacent_water(int y, int x) {
    int cnt=0;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(map[ny][nx]==0) {
            cnt++;
        }
    }    
    return cnt;
}
void after_one_sec() {
    for(int i=1;i<N;i++) {
        for(int j=1;j<M;j++) {
            decreasing[i][j]-=adjacent_water(i,j);
        }
    }
    for(int i=1;i<N;i++) {
        for(int j=1;j<M;j++) {
            if(map[i][j]!=0) {
                map[i][j]+=decreasing[i][j];
                if(map[i][j]<0) {
                    map[i][j]=0;
                }
            }
            
        }
    }
    memset(decreasing,0, sizeof(int)*301*301);
}
int bfs(int b, int a) {
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
            if(nx>=0 && ny>=0 && nx<M && ny<N && !visited[ny][nx] && map[ny][nx]!=0) {
                visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }

        }
    }
    return 1;
}
int temp_2=0;

int how_many_island() {
    temp_2=0;
    memset(visited,false,301*301);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(!visited[i][j] && map[i][j]!=0) {
                temp_2+=bfs(i,j);
            }
        }
    }
    return temp_2;
}
// void init() {
//     memset(visited, false, 301*301);
//     for(int i=0;i<N;i++) {
//         for(int j=0;j<M;j++) {
//             map[i][j]=map2[i][j];
//         }
//     }
// }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>map[i][j];
        }
    }
    int answer=0;
    for(int i=1;i<=10;i++) {
        if(how_many_island()>=2) {
            answer=i-1;
            break;
        }
        after_one_sec();
    }
    
    cout<<answer;

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    return 0;
}