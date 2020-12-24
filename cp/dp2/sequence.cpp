#include<bits/stdc++.h>
using namespace std;
int printsub(string s,string output){
    if(s.length()==0){
        return 1;
    }
    int ans1=printsub(s.substr(1),output);
    int ans2=printsub(s.substr(1),output+s[0]);
    return ans1+ans2;
}
int main(){
    int t;
    cin>>t;
    while(t--){ 
        string s;
        cin>>s;
        cout<<printsub(s,"")<<endl;
    }
    return 0;
}