#include <iostream>
#include<string>
#include<vector>
using namespace std;
int *getlps(string pattern){
int m=pattern.length();
int *lpsarr=new int[m];
lpsarr[0]=0;
int i=1;
int j=0;
while(i<m){
 if(pattern[i]==pattern[j]){
lpsarr[i]=j+1;
 i++;
j++;
}
else{
 if(j!=0){
    j=lpsarr[j-1];
}else{
 lpsarr[i]=0;
i++;
}
}
}
return lpsarr; 
}
int findString(char s[],char t[]){
string text="";
string pattern="";
for(int i=0;s[i]!='\0';i++){
 text+=s[i];
}
for(int i=0;t[i]!='\0';i++){
 pattern+=t[i];
}
int i=0,j=0;
int *lps=getlps(pattern);
int m=text.length();
int n=pattern.length();                                           
while(i<m&&j<n){
   if(text[i]==pattern[j]){
 i++;
j++;
}else{
if(j!=0){
 j=lps[j-1];
}else{
 i++;
}
}
}
if(j==n){
return i-j;
}else{
 return -1;
}
}
int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
