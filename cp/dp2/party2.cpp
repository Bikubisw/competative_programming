#include <bits/stdc++.h>
using namespace std;
int main()
{
     while (1) {
        int maximum,n;
        cin>>maximum>>n;
        if (maximum == 0 && n == 0)
        {
            break;
        }
        vector<int> fees;
        vector<int> fun;
        for (int i = 0; i < n; i++)
        {
            int first, second;

            cin >> first >> second;
            fees.push_back(first);
            fun.push_back(second);
        }
        int dp[n + 1][maximum + 1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for (int j = 0; j <= maximum; j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for (int j = 1; j <= maximum; j++)
            {
                dp[i][j]=dp[i-1][j];
                if(fees[i-1]<=j){
                    dp[i][j]=max(dp[i][j],fun[i-1]+dp[i-1][j-fees[i-1]]);
                }
            }
        }
        int ans=maximum;
        for(int i=0;i<=maximum;i++){
            if(dp[n][i]==dp[n][maximum]){
                ans=i;
                break;
            }
        }
        cout<<ans<<" "<<dp[n][maximum]<<endl;
     }
    
    return 0;
}