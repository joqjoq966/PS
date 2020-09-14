#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b)
{
    return a.length()>b.length();
}

bool sorting(pair<char,int> &a, pair<char,int> &b)
{
    return a.second>b.second;
}

int sum(vector<pair<char, int> > &v)
{
    int arr[26]={0};
    for(int i=0;i<v.size();++i)
    {
        arr[v[i].first-'A']+=v[i].second;
        for(int j=i+1;j<v.size();++j)
        {
            if(v[i].first==v[j].first)
            {
                arr[v[i].first-'A']+=v[j].second;
                v[j].second=0;
            }
        }
    }
    sort(arr,arr+26,greater<int>());
    int temp=0;
    for(int i=0;i<10;++i)
    {   
        temp+=arr[i]*(9-i);
    }
    return temp;
}
int main()
{
    int num;
    scanf("%d",&num);
    vector <string> v;
    v.clear();
    for(int i=0;i<num;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);

    }
    
    vector<pair<char, int> > match;

    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v[i].length();++j)
        {
            match.push_back(make_pair(v[i].at(j),pow(10,v[i].length()-j)));
        }
    }
    sort(match.begin(),match.end(),sorting);

    int result=sum(match);
    
    printf("%d",result/10);


    return 0;
}