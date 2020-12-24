#include <iostream>
using namespace std;
 
int maxProfit(int price[], int n, int k)
{
    int profit[k+1][n+1];
    
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    for (int j= 0; j <= n; j++)
        profit[0][j] = 0;
 
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int max_so_far =  0;
 
            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                   price[j] - price[m] + profit[i-1][m]);
 
            profit[i][j] = max(profit[i][j-1], max_so_far);
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            cout<<profit[i][j]<<" ";
        }
        cout<<endl;
    }
 
    return profit[k][n-1];
}

int main()
{
    int k,n,t;
    
    cin>>t;
    
    for(int j = 0; j < t; j++)
    {
    	cin>>k;
    	cin>>n;
    	int price[n];
    	
        for(int i = 0; i < n; i++)
    		cin>>price[i];
 
    	cout<< maxProfit(price, n, k)<<endl;
    }
    return 0;
}