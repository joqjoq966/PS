#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int num,target,cnt=0;
    scanf("%d %d",&num,&target);
    
    int arr[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&arr[i]);
    }
    int sum=0,result=0;
    
    for(int i=0;i<num;i++)
    {
        int j=i;
        sum=0;
        while(1)
        {
            sum+=arr[j];
            if(sum>target)
                break;
            else if(sum==target)
            {
                cnt++;
                break;
            }
            j++;
        }
    }
    printf("%d",cnt);
    return 0;
}