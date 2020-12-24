#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string a,b;
cin>>a>>b;
int m=a.length();
int n=b.length();
vector<vector<int>>next(m+1,vector<int>(n+1));
  vector<vector<int>>dp(m+1,vector<int>(n+1));
int prev;
for(int i=0;i<m;i++) {
  prev=-1;
for(int j=0;j<n;j++){
 if(a[i]==b[j]){
 prev=j;

}
 next[i+1][j+1]=prev;
}

}
for(int i=1;i<=m;i++){
 for(int j=1;j<=n;j++){
 cout<<next[i][j]<<" ";
}
cout<<endl;
}
for(int i=1;i<=m;i++){
dp[i][0]=1;

}
for(int i=0;i<=n;i++){
 dp[0][i]=1001;
}
for(int i=1;i<=m;i++){
 for(int j=1;j<=n;j++){
 if(next[i][j]==-1){
 dp[i][j]=1;

}else{
  dp[i][j]=min(dp[i-1][j],1+dp[i-1][next[i][j]]);
}
}

}
cout<<dp[m][n]<<endl;
return 0;

}









