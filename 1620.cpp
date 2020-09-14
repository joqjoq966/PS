#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;

    vector<pair<string,int> > poketmon;
    vector<pair<string,int> > poketmon2;
    poketmon.push_back(make_pair("",0));
    poketmon2.push_back(make_pair("",0));
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        poketmon.push_back(make_pair(s,i));
        poketmon2.push_back(make_pair(s,i));
    }
    sort(poketmon.begin(),poketmon.end());
    vector<string> quiz;
    
    for(int i=1;i<=M;i++)
    {   
        string s;
        cin>>s;
        int idx;
        if(s[0]>='0' && s[0]<='9')
        {
            idx = atoi(s.c_str());
            cout<<poketmon2[idx].first<<"\n";
        }
        else
        {
            int low=0,high=N;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(poketmon[mid].first==s)
                {
                    cout<<poketmon[mid].second<<"\n";
                    break;
                }
                else
                {
                    if(poketmon[mid].first<s)
                        low=mid+1;
                    else
                    {
                        high=mid-1;
                    }
                    
                }
                
            }
        }
        
    }   
    return 0;
}