#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

bool cmp(pair<int,int> &x, pair<int,int> &y)
{
    return x.first<y.first;
}
int main()
{
    int testcase;
    scanf("%d",&testcase);
    while(testcase--)
    {
        int num_app;
        scanf("%d",&num_app);
        int num;
        num=num_app;
        vector<pair<int,int> > rank;
        while(num--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            rank.push_back(make_pair(a,b));
        }
        sort(rank.begin(),rank.end(),cmp);
        
        int temp=rank[0].second;
        int cnt=num_app;
        for(int i=1;i<num_app;i++)
        {
            if(rank[i].second>temp)
            {
                cnt--;
            }
            temp=rank[i].second;
        }
        //printf("\n%d %d\n",rank[2].first,rank[2].second);
        printf("%d\n",cnt);
        
        
    }

    return 0;
}