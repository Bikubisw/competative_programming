#include<bits/stdc++.h>
using namespace std;
int longest(string s){
int n=s.length();
int count=0;
for(int i=0;i<n;i++){
 int l=i;
int r=i;
while(l>=0&&r<n&&s[r]==s[l]){
int currlen=r-l+1;
if(currlen>1){
 count++;
}
 l--;
r++;
}
l=i;
r=i+1;
while(l>=0&&r<n&&s[r]==s[l]){
int currlen=r-l+1;
if(currlen>1){
 count++;
}
 l--;
r++;
}
}
return count;
}
int main(){
string s;
getline(cin,s);
cout<<longest(s)<<endl;
 return 0;
}