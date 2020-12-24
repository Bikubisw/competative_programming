#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin>>p;
    int count=0;
    int n=0;
    while(count<p){
        int ele=3*n+5;
        if(ele%5==0){
            continue;
        }else{
            cout<<ele<<endl;
        }
        count++;

        n++;
    }

    return 0;
}