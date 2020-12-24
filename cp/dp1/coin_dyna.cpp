#include <bits/stdc++.h>
using namespace std;
int coinchange(int n, int *arr, int val)
{
    int output[val+1][n];
    for(int i=0;i<n;i++){
        output[0][i]=1;
    }
    int x,y;
    for(int i=1;i<=val;i++){
        for(int j=0;j<n;j++){
            // including arr[j]
            if(i-arr[j]>=0){
                x=output[i-arr[j]][j];
            }
            else{
                x=0;
            }
            if(j>=1){
                y=output[i][j-1];
            }else{
                y=0;
            }
            output[i][j]=x+y;
        }
    }
    for(int i=0;i<=val;i++){
        for(int j=0;j<n;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return output[val][n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int val;
    cin >> val;
    cout << coinchange(n, arr, val) << endl;
    return 0;
}