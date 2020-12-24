#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int minfair(int arr[][101],int i,int j,int n,int m){
    if(i>n||j>m||j<0){
        return INT_MAX;
    }
    if(i==n){
        return arr[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int option1=minfair(arr,i+1,j,n,m);
    int option2=minfair(arr,i+1,j-1,n,m);
    int option3=minfair(arr,i+1,j+1,n,m);
    int ans= min(option1,min(option2,option3))+arr[i][j];
    dp[i][j]=ans;
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[101][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    int ans=INT_MAX;
    for(int i=0;i<m;i++){
    int finalans=minfair(arr,0,i,n-1,m-1);
    ans=min(ans,finalans);
    }
    cout<<ans<<endl;
    return 0;
}