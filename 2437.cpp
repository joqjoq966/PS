#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int scale(int arr[],int num)
{
    int result,sum=0;
    if(arr[0]!=1)
        return 1;
    for(int i=1;i<num;++i)
    {
        sum=0;
        for(int j=0;j<i;++j)
        {
            sum+=arr[j];
        }
        if(arr[i]-sum>=2)
        {
            return (sum+1);
        }
    }
    return sum+arr[num-1]+1;
}
int main()
{
    int num;
    scanf("%d",&num);

    int arr[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+num);
    
    int result=scale(arr,num);
    printf("%d",result);

    return 0;
}