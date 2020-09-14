#include<iostream>
#include<string>
#include<list>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int num;
    cin>>num;

    list<char> c;
    for(int i=0;i<s.size();i++) {
        c.push_back(s[i]);
    }
    list<char>::iterator now=c.end();

    while(num--) {
        char order;
        cin>>order;
        if(order=='L') {
            if(now==c.begin()) {
                continue;
            }
            else {
                now--;
            }
        }
        else if(order=='D') {
            if(now==c.end()) {
                continue;
            }
            else {
                now++;
            }
        }
        else if(order=='B') {
            if(now==c.begin()) {
                continue;                
            }
            else {
                now=c.erase(--now);
            }
        }
        else {
            char new_ch;
            cin>>new_ch;
            c.insert(now,new_ch);
        }
    }
    for(auto iter=c.begin();iter!=c.end();iter++) {
        cout<<*iter;
    }

    return 0;
}




// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     string s;
//     cin>>s;
//     int num;
//     cin>>num;
//     int now=s.size();
//     int new_size=s.size();
//     while(num--) {
//         char order;
//         cin>>order;
//         if(order=='P') {
//             string xy;
//             cin>>xy;
//             s.insert(now,xy);
//             now++;
//             new_size++;
//         }
//         else if(order=='L') {
//             if(now!=0)
//                 now--;
//             else
//             {
//                 continue;
//             }
//         }
//         else if(order=='D'){
//             if(now<new_size)
//                 now++;
//             else {
//                 continue;
//             }
//         }
//         else if(order=='B') {
//             if(now>0) {
//                 s.erase(now-1,1);
//                 now--;
//                 new_size--;
//             } 
//         }
//     }
//     cout<<s<<endl;

//     return 0;
// }//시간초과
