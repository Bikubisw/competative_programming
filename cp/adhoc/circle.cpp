#include<bits/stdc++.h>
using namespace std;
#define T 12; 
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,p;
        cin>>i>>p;
        int ans=(i+p)%T;
        cout<<ans<<endl;
    }
    return 0;
}