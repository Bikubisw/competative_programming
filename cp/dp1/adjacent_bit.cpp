#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
typedef long long ll;
ll dp[101][101][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][0][0]=1;
    dp[1][0][1]=1;
    for(int i=2;i<=100;i++){
        dp[i][i-1][0]=0;
        dp[i][i-1][1]=1;
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][0][0]=dp[i][0][0]%MOD;
    }
    for(int i=2;i<=100;i++){
        for(int j=1;j<i;j++){
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
            dp[i][j][0]=dp[i][j][0]%MOD;
            dp[i][j][1]=dp[i][j][1]%MOD;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int i,n,k;
        cin>>i>>n>>k;
        if(n==0&&k==0){
            cout<<i<<" "<<1<<endl;
        }else{
            ll ans=dp[n][k][0]+dp[n][k][1];
            ans=ans%MOD;
            cout<<i<<" "<<ans<<endl;
        }

    }
}





















// #include<bits/stdc++.h>
// using namespace std;
// int count(int n,int k,int first){
//     if(n==1){
//         if(k==0){
//             return 1;
//         }
//         if(k>=1){
//             return 0;
//         }
//         if(k<0){
//             return 0;
//         }
//         return 0;
//     }
//     int ans1=0;
//     if(first==1){
//         ans1+=count(n-1,k-1,1);
//         ans1+=count(n-1,k,0);
//     }
//     if(first==0){
//         ans1+=count(n-1,k,1);
//         ans1+=count(n-1,k,0);
//     }
//    return ans1;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,k;
//     cin>>n>>k;
//     int ans1=count(n,k,1);
//     int ans2=count(n,k,0);
//     cout<<ans1+ans2<<endl;
//     return 0;
// }