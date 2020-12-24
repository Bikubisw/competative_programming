#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    map<string,int> mp;
    string word="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            mp[word]++;
            word="";
        }else{
            word=word+s[i];
        }
    }
    mp[word]++;
    bool ans=true;
    map<string,int>:: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if(it->second>=2){
            cout<<it->first<<" "<<it->second<<endl;
            ans=false;
        }
    }
    if(ans){
        cout<<"-1"<<endl;
    }
   
}