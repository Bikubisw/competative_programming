#include <bits/stdc++.h>
using namespace std;
// int common(string s,string t){
//     if(s.length()==0){
//         return t.length();
//     }
//     if(t.length()==0){
//         return s.length();
//     }
//     if(s[0]==t[0]){
//         return 1+common(s.substr(1),t.substr(1));
//     }
//     else{
//         int option1=common(s.substr(1),t);
//         int option2=common(s,t.substr(1));
//         return 1+min(option1,option2);
//     }
// }
int main()
{
    string s,t;
    cin>>s>>t;
    int m=s.length();
    int n=t.length();
    int dp[m+1][n+1];
    dp[m][n]=0;
    int k=1;
    for(int i=m-1;i>=0;i--){
        dp[i][n]=k;
        k++;
    }
    k=1;
    for(int i=n-1;i>=0;i--){
        dp[m][i]=k;
        k++;
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }else{
                dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][0]<<endl;
}