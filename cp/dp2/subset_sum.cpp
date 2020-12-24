#include <bits/stdc++.h>
using namespace std;

int possible(vector<int> arr,int n,int sum)
{
    bool dp[2][sum + 1];
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = false;
    }
    dp[0][0]=true;
    int flag=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[flag][j] = dp[flag^1][j];
            if (arr[i - 1] <= j)
            {
                dp[flag][j] =dp[flag^1][j - arr[i - 1]]||dp[flag][j];
            }
        }
        flag=flag^1;
    }
    return dp[flag^1][sum];
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int sum;
    cin>>sum;
    if(possible(arr,n,sum)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}