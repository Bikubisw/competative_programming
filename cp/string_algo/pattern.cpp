#include<bits/stdc++.h>
using namespace std;
bool ismatching(string s,string p){
 for(int i=0;i<=s.length()-p.length();i++){
 bool isfound=true;
for(int j=0;j<p.length();j++){
 if(s[i+j]!=p[j]){
  isfound=false;
break;
}
}
if(isfound){
return true;
}
}
return false;
}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s,p;
getline(cin,s);
getline(cin,p);
cout<<ismatching(s,p)<<endl;

return 0;
}