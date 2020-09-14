#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool minus=false;
    char op;
    int sum,next;

    scanf("%d",&sum);
    while(true) {
        scanf("%c",&op);
        scanf("%d",&next);
        if(op=='-') {
            minus=true;
        }
        else if(op!='+'){
            break;
        }

        if(minus) {
            sum-=next;
        }
        else
        {
            sum+=next;
        }
    }

    cout<<sum;
    return 0;
}