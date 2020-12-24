#include<bits/stdc++.h>
using namespace std;
void name(string s){
    map<string,int> ourmap;
    string input;
    int j=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            input[j]=s[i];
            j++;
        }
        else{
            ourmap[input]++;
            co
            cout<<ourmap.at(input)<<endl;
            j=0;
        }
    }
}
int main()
{
    string s;
    cin>>s;
    name(s);
}