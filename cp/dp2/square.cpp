#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int noway(int n,int open,int close,bool* check,int dp[][20]){
    if(open>n||close>n){
        return 0;
    }
    if(open==n&&close==n){
        return 1;
    }
    if(dp[open][close]!=-1){
        return dp[open][close];
    }
    if(open==close||check[open+close]==true){
        int ans= noway(n,open+1,close,check,dp);
        dp[open][close] = ans;
        return ans;
    }
    else if(open==n){
        int ans= noway(n,open,close+1,check,dp);
        dp[open][close] = ans;
        return ans;
    }
    else{
        int ans=noway(n,open+1,close,check,dp)+noway(n,open,close+1,check,dp);
        dp[open][close]=ans;
        return ans;
    }
}
int main()
{  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;cin>>t;
   while(t--){
       int n;cin>>n;
       int k;
       cin>>k;
       int arr[k];
       for(int i=0;i<k;i++){
           cin>>arr[i];
       }
       bool check[2*n];
       memset(check,false,sizeof check);
       for(int i=0;i<k;i++){
           check[arr[i]-1]=true;
       }
       int dp[20][20];
       memset(dp, -1, sizeof dp);
       cout<<noway(n,0,0,check,dp)<<endl;
       

   }
}