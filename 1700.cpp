#include<iostream>

using namespace std;

int n,k;
int multi[102],item[102];
int us=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>item[i];

    int cnt=0;
    for(int i=0;i<k;i++)
    {
        int j;
        for(j=0;j<us;j++)
        {
            if(multi[j]==item[i])
                break;
        }
        if(j==n)
        {
            int maxi=0,midx;
            int p;
            for(j=0;j<us;j++)
            {
                for(p=i+1;p<k && item[p]!=multi[j];p++);
                if(p>maxi)
                {
                    maxi=p;
                }
                midx=j;    
            }
            multi[midx]=item[i];
            cnt++;
        }
        else if(j==us)
        {
            multi[us++]=item[i];
        }
    }
    cout<<cnt;


    return 0;
}

/*int N,K;
int multi[101]={0,};
int item[101]={0,};
bool connected(int item_num)
{
    for(int i=0;i<N;i++)
    {
        if(multi[i]==item_num)
            return true;
    }
    return false;
}
int next_itself(int start_idx,int a)
{
    for(int i=start_idx;i<K;i++)
    {
        if(item[i]==a)
        {
            return i;
        }
    }
    return K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin>>N>>K;
    int cnt=0;

    for(int i=0;i<K;i++)
    {
        cin>>item[i];
    }
    for(int i=0;i<N;i++)
    {
        int j=i;
        while(j<K)
        {
            if(!connected(item[j]))
            {
                multi[i]=item[j];
                break;
            }
            else
            {
                j++;
            }
        }
    }
    for(int i=N;i<K;i++)
    {
        if(!connected(item[i]))
        {
            int max=0;
            for(int j=0;j<N;j++)
            {
                if(max<next_itself(i,multi[j]))
                {
                    max=next_itself(i,multi[j]);
                    if(max==K)
                    {
                        multi[j]=item[i];
                        break;
                    }
                }
            }
            for(int j=0;j<N;j++)
            {
                if(multi[j]==item[max])
                {
                    multi[j]=item[i];
                    break;
                }
            }
            cnt++;
        }
        else
        {
            continue;
        }
        
    }
    cout<<cnt;

    return 0;
}*/