#include<bits/stdc++.h>
using namespace std;
int profit(int k,int n ,int *arr,int ongoing,int dp[][10][2]){
    if(n==0){
        return 0;
    }
    if(dp[n][k][ongoing]!=-1){
        return dp[n][k][ongoing];
    }

    int ans=profit(k,n-1,arr+1,ongoing,dp);
    if(ongoing){
        int option1=profit(k-1,n-1,arr+1,0,dp)+arr[0];
        ans=max(ans,option1);
    }else{
            if(k>0){
            int option2=profit(k,n-1,arr+1,1,dp)-arr[0];
            ans=max(ans,option2);
            }
    }
        
    dp[n][k][ongoing]=ans;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int k;
    cin>>k;
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[30][10][2];
    memset(dp,-1,sizeof dp);
    cout<<profit(k,n,arr,0,dp)<<endl;
    }

    return 0;
}