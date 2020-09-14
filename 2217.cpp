#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a,int b) {
    return a>b;
}
vector<int> rope;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    while(n--) {
        int w;
        cin>>w;
        rope.push_back(w);
    }
    sort(rope.begin(),rope.end(),cmp);
    int sum=0;
    for(int i=0;i<rope.size();i++) {
        arr.push_back(rope[i]*(i+1));
    }
    sort(arr.begin(),arr.end(),cmp);

    cout<<arr[0]<<endl;
    return 0;
}