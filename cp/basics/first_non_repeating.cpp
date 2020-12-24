#include<bits/stdc++.h>
using namespace std;
char first(string s){
    map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    for(int i=0;i<s.size();i++){
        if(m[s[i]]==1){
            return s[i];
        }
    }
    return s[0];
}
int main(){
    string s;
    cin>>s;
    cout<<first(s)<<endl;
    return 0;
}