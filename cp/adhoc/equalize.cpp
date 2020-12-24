#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cost=0;
    int i=0;
    while(i<n){
        if(s[i]!=t[i]){
            if(i+1<n&&s[i+1]!=t[i+1]&&s[i]!=s[i+1]){
                i+=2;
            }else{
                i++;
            }
            cost+=1;
        }
        else{
            i++;
        }
    }
    cout<<cost<<endl;
    return 0;
}