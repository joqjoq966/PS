#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{   
    int num,sum=0;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+num);
    int i=0,j=num-1;
    while(arr[i]<0 && arr[i+1]<0)
    {
        sum+=(arr[i]*arr[i+1]);
        i+=2;
    }
    while(arr[j]>1 && arr[j-1]>1)
    {
        sum+=arr[j]*arr[j-1];
        j-=2;
    }
    while(i<=j)
    {
        if(arr[i+1]==0 && i<=num-1)
            i++;
        else
        {
            sum+=arr[i];
            i++;
        }
    }
    printf("%d",sum);

    return 0;
}