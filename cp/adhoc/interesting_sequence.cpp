#include <bits/stdc++.h>
using namespace std;
int eachcost(int*arr,int n,int pivot,int k,int l){
    int inc=0;
    int dec=0;
    for(int i=0;i<n;i++){
        if(arr[i]<pivot){
            inc+=pivot-arr[i];
        }
        else if(arr[i]>pivot){
            dec+=arr[i]-pivot;
        }
    }
    int cost=INT_MAX;
    if(inc>=dec){
        cost=(dec*k)+((inc-dec)*l);
    }
    return cost;
}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int mincost=INT_MAX;
    for(int i=min;i<=max;i++){
        int cost=eachcost(arr,n,i,x,y);
        if (cost < mincost)
        {
            mincost = cost;
        }
    }
    cout << mincost << endl;

    return 0;
}