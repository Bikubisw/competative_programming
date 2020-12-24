#include<bits/stdc++.h>
using namespace std;
char getchar(int i){
    return char(i+97);
}
void stringper(string s){
    map<char,vector<int>> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]].push_back(i);
    }
    int oddcount=0;
    for(int i=0;i<26;i++){
        if(mp[getchar(i)].size()%2!=0){
            oddcount++;
        }
    }
    if(oddcount>=2){
        cout<<"-1";
        return;
    }
    int ans[s.length()];
    int start=0;
    int end=s.length()-1;
    for(int i=0;i<26;i++){
        for(int j=0;j<mp[getchar(i)].size();j+=2){
            if(mp[getchar(i)].size()-j==1){
                ans[s.length()/2]=mp[getchar(i)][j];
                continue;
            }
            ans[start]=mp[getchar(i)][j];
            ans[end]=mp[getchar(i)][j+1];
            start++;
            end--;
        }
    }
    for(int i=0;i<s.length();i++){
        cout<<ans[i]+1<<" ";
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stringper(s);
        cout<<endl;
    }
}