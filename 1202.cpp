#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pair<int,int> > jew;
    vector<int> bag;
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++)
    {
        int m,v;
        scanf("%d %d",&m,&v);
        jew.push_back(make_pair(m,v));
    }
    for(int i=0;i<k;i++)
    {
        int c;
        scanf("%d",&c);
        bag.push_back(c);
    }
   
    sort(jew.begin(),jew.end());
    sort(bag.begin(),bag.end());
    
    long long sum=0;
    int idx=0;
    for(int i=0;i<k;i++)
    {
        while(idx<n && jew[idx].first<=bag[i])
        {
            pq.push(jew[idx].second);
            idx++;
        }
        if(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
    }
    printf("%d",sum);
    return 0;
}