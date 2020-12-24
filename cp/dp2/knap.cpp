#include<bits/stdc++.h>
using namespace std;

int knapsack(int *weights, int *values, int n, int w)
{
    int dp[2][w+1];
    for(int i=0;i<=1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=w;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[1][j]=dp[0][j];
            if(weights[i-1]<=j){
                dp[1][j]=max(values[i-1]+dp[0][j-weights[i-1]],dp[1][j]);
            }
        }
        for(int i=0;i<=w;i++){
            dp[0][i]=dp[1][i];
        }
    }
    return dp[1][w];

}
int main()
{

    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight);
}