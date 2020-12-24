#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2,int m,int n,int **dp){
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    int ans;
    if(s1[0]==s2[0]){
        return 1+lcs(s1.substr(1),s2.substr(1),m-1,n-1,dp);
    }
    else{
        int option1=lcs(s1,s2.substr(1),m,n-1,dp);
        int option2=lcs(s1.substr(1),s2,m-1,n,dp);
         ans=max(option1,option2);
    }
    dp[m][n] = ans;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }

    cout<<lcs(s1,s2,m,n,dp)<<endl;
    for(int i=0;i<=m;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}