#include<iostream>
#include<vector>

#define MAX 4000000

using namespace std;

vector<int> prime;
long long  minFactor[MAX]={0,};

void eratosthenes() {
    minFactor[0]=-1;
    minFactor[1]=-1;
    for(long long i=2; i<MAX;i++) {
        minFactor[i]=i;
    }

    for(long long i=2;i<MAX;i++) {
        if(minFactor[i]==i) {
            for(long long j=i*i;j<MAX;j+=i) {
                if(minFactor[j]==j) {
                    minFactor[j]=i;
                }
            }
        }
    }
    for(long long i=2;i<MAX;i++) {
        if(minFactor[i]==i) {
            prime.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    eratosthenes();

    int low=0,high=0,result=0;
    int sum=prime[0];

    while(low<=high && high<prime.size() && prime[low]<=N) {
        if(sum<N) {
            high++;
            sum+=prime[high];
        }
        else if(sum==N) {
            result++;
            high++;
            sum+=prime[high];
        }
        else if(sum>N) {
            sum-=prime[low];
            low++;
            if(low>high && low<prime.size()) {
                high=low;
                sum=prime[low];
            }
        }
    }
    cout<<result;
    return 0;
}