#include<bits/stdc++.h>
using namespace std;
int maxsum (int**arr,int row,int col){
    int dp[row][col];
    for(int i=0;i<col;i++){
        dp[0][i]=arr[0][i]==0?1:0;
    }
    for(int j=1;j<row;j++){
        dp[j][0]=arr[j][0]==0?1:0;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]!=1){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }else{
                dp[i][j]=0;
            }
        }
    }
    int maximum=dp[0][0];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maximum = max(dp[i][j], maximum);
        }
    }
    return maximum;

}
    int main()
{
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
cout<<maxsum(arr,m,n)<<endl;

    return 0;
}