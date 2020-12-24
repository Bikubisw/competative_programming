#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("mixin.txt", "r", stdin);
    freopen("mixout.txt", "w", stdout);
    int r,s;
    cin>>r>>s;
    int a=r/s;
    int b=r%s;
    if(b!=0){
        cout<<a<<" "<<b<<"/"<<s<<endl;
    }
    else{
        cout<<a<<endl;
    }
}