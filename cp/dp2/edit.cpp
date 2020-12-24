#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
    }
    cout<<dp[m][n]<<endl;    
}
// int edit(string s1, string s2)
// {
//     //     if(s1.length()==0){
//     //         return s2.length();
//     //     }if(s2.length()==0){
//     //         return s1.length();
//     //     }
//     //     if(s1[0]==s2[0]){
//     //         return edit(s1.substr(1),s2.substr(1));
//     //     }
//     //     else{
//     //         int option1=1+edit(s1.substr(1),s2.substr(1));
//     //         int option2=1+edit(s1.substr(1),s2);
//     //         int option3=1+edit(s1,s2.substr(1));
//     //         return min(option1,min(option2,option3));
//     //     }
//     // }