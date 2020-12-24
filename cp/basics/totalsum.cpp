#include <bits/stdc++.h>
using namespace std;
int totalsum(int **arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[0][i];
    }
    for(int i=1;i<n;i++){
        sum+=arr[i][n-1];
    }
    for(int i=n-2;i>=0;i--){
        sum+=arr[n-1][i];
    }
    for(int i=n-2;i>=1;i--){
        sum+=arr[i][0];
    }
    for(int i=1,j=1;i<n-1&&j<n-1;i++,j++){
        sum+=arr[i][j];
    }
    for(int i=1,j=n-2;i<n-1&&j>=1;j--,i++){
        sum+=arr[i][j];
    }
    if(n%2!=0){
        sum=sum-arr[n/2][n/2];
    }
return sum;
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t1;
    cin>>t1;
    while(t1--){
        int n;
        cin>>n;
        int**arr=new int*[n];
        for(int i=0;i<n;i++){
            arr[i]=new int[n];
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
            
        }
        int sum = totalsum(arr, n);
        cout << sum << endl;
    }
    return 0;
}