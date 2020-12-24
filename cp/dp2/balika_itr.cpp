#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101],lcs[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        memset(dp,0,sizeof dp);
        memset(lcs,0,sizeof lcs);
        int m=s1.length();
        int n=s2.length();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
            for(int z=0;z<=k;z++){
                if(i==0||j==0){
                    dp[i][j][z]=0;
                }else if(s1[i-1]==s2[j-1]){
                    if(z==0){
                        dp[i][j][z]=0;
                    }else{
                        dp[i][j][z]=max(dp[i-1][j-1][z-1]+(int)s1[i-1],max(dp[i-1][j][z],dp[i][j-1][z]));
                    }
                }else{
                    if(z==0){
                        dp[i][j][z]=0;

                    }else{
                        dp[i][j][z]=max(dp[i-1][j][z],dp[i][j-1][z]);
                    }
                }
            }

        }

}
for (int i = 0; i <= m; i++)
{
    lcs[i][0] = 0;
}
for (int i = 0; i <= n; i++)
{
    lcs[0][i] = 0;
}
for (int i = 1; i <= m; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (s1[m - i] == s2[n - j])
        {
            lcs[i][j] = 1 + lcs[i - 1][j - 1];
        }
        else
        {
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
}
int ans = lcs[m][n];
if(ans<k){
    cout<<0<<endl;
}else{
    cout<<dp[m][n][k]<<endl;
}

    
    }
    return 0;
}