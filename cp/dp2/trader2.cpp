#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int k;
    cin >> k;
    int n;
    cin >> n;
    int arr[30];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[k+1][n+1];
    for(int i=0;i<=k;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    bool ans=false;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(ans){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+arr[j-1]);
                ans=false;
            }else{
                dp[i][j]=max(dp[i][j],dp[i][j-1]-arr[j-1]);
                ans=true;
            }
        }
    }
    cout<<dp[n][k]<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    }
    return 0;
}