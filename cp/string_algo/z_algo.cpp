#include<bits/stdc++.h>
using namespace std;
void stringsearch(int*z,string str){
int l=0;
int r=0;
int n=str.length();
for(int i=1;i<n;i++){
if(i>r){
l=i;
r=i;
while(r<n&&str[r-l]==str[r]){
 r++;
}
z[i]=r-l;
r--;
}else{
 int k=i-l;
if(z[k]<=r-i){
 z[i]=z[k];
}else{
 l=i;
while(r<n&&str[r-l]==str[r]){
r++;
}
z[i]=r-l;
r--;
}
}
}
}
void zalgo(string text,string pattern){
string str=pattern+"$"+text;
int m=str.length();
int*z=new int[m]();
stringsearch(z,str);
for(int i=0;i<m;i++){
 if(z[i]==pattern.length()){
 cout<<i-pattern.length()-1<<endl;
}
}

}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
string text,pattern;
getline(cin,text);
getline(cin,pattern);
zalgo(text,pattern);
return 0;
}