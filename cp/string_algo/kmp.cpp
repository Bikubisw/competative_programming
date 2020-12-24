#include<bits/stdc++.h>
using namespace std;
int* getlps(string pattern){
 int m=pattern.length();
int *lcs=new int[m];
lcs[0]=0;
int i=1;
int j=0;
while(i<m){
 if(pattern[i]==pattern[j]){
lcs[i]=j+1;
 i++;
j++;
}else{
 if(j!=0){
j=lcs[j-1];
}else{
 lcs[i]=0;
i++;
}
}
}
return lcs;
}
bool kmp(string text,string   pattern){
int m=text.length();
int n=pattern.length();
int i=0,j=0;
int *lcs=getlps(pattern);
while(i<m&&j<n){
 if(text[i]==pattern[j]){
 i++;
j++;
}
else{
 if(j!=0){
     j=lcs[j-1];
}else{
 i++;
}
}
}
if(j==n){
  return true;
}
 return false;
}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s,p;
getline(cin,s);
getline(cin,p);
cout<<kmp(s,p)<<endl;


return 0;
}