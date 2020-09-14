#include<iostream>

using namespace std;

int main()
{
    int x,k;
    cin>>x>>k;
    int cnt=0;
    int arr[100000]={0,};
    for(int i=0;i<1000000;i++)
    {
        if((x+i)==(x|i))
        {
            arr[cnt]=i;
            cnt++;
        }
    }

    cout<<arr[k];
    return 0;
}