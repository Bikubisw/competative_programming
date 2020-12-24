#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m+1];
    for(int i=1;i<=m;i++){
        arr[i]=new int[n+1];
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    int dp[m+1][n+1];
    for(int i=1;i<=n;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]>=arr[i-1][j]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=i;
            }
        }
    }
    int *output=new int[m+1];
    for(int i=1;i<=m;i++){
        int minimum = INT_MAX;
        for(int j=1;j<=n;j++){
            minimum=min(minimum,dp[i][j]);
        }
        output[i]=minimum;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int first,second;
        cin>>first>>second;
        if(output[second]<=first){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
  return 0;    
}