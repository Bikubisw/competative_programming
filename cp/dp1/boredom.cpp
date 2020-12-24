#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> A;
int dp[1002],freq[1002];
int solve(int n,vector<int> arr){
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=1000;i++){
        dp[i]=max(dp[i-1],dp[i-2]+(i*freq[i]));
    }
    return dp[1000];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << solve(n, A) << endl;
}