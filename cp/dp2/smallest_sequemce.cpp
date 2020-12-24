#include<bits/stdc++.h>
using namespace std;
int smallhelper(string s1,string s2,int si1,int si2,int **dp)
{
 if(si2==s2.length()){
 return 1;}
 if(si1==s1.length()){
return 1001;

}
if(dp[si1][si2]!=-1){

 return dp[si1][si2];

}
int option1=smallhelper(s1,s2,si1+1,si2,dp);
int index=-1;
for(int i=si2;i<s2.length();i++){
if(s1[si1]==s2[i]){
  index=i;

break;

}

}
if(index==-1){
return 1;

}
int option2=1+smallhelper(s1,s2,si1+1,index+1,dp);
int ans= min(option1,option2);
dp[si1][si2]=ans;
return ans;
}
int small(string s1,string s2){
int m=s1.length();
int n=s2.length();
   int**dp=new int*[m+1];
for(int i=0;i<=m;i++){
 dp[i]=new int[n+1];
for(int j=0;j<=n;j++){
 dp[i][j]=-1;
}
}
int ans= smallhelper(s1,s2,0,0,dp);
   for(int i=0;i<=m;i++){
 delete[] dp[i];
}
delete[]dp;
return ans;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s1,s2;
cin>>s1>>s2;
cout<<small(s1,s2)<<endl;
return 0;
}