#include <bits/stdc++.h>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if(n==0){
        return 0;
    }
    int option1=0;
    if (weights[0] <= maxWeight)
    {
        option1 = values[0] + knapsack(weights + 1, values+1, n - 1, maxWeight-weights[0]);
    }
    int option2=knapsack(weights+1,values+1,n-1,maxWeight);
    return max(option1,option2);
}

int main()
{

    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];

   for(int i=0;i<n;i++){
	cin>>weights[i];
	}

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight);
}
