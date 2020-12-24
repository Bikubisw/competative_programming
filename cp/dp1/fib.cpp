#include<bits/stdc++.h>
using namespace std;
int fib(int n,int *arr){
    
    if(n==0||n==1){
        return 1;
    }
    if(arr[n]>0){
        return arr[n];
    }

    int ans= fib(n-1,arr)+fib(n-2,arr);
    arr[n]=ans;
    return ans;
}
int fib2(int n){
    int*arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    int ans=arr[n];
    delete[] arr;
    return ans;
}
int main(){
    int n;
    cin>>n;
    // int arr[n+1]={0};
    // cout<<fib(n,arr)<<endl;
    cout<<fib2(n)<<endl;
    return 0;
}