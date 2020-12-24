#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int i=0;
    int j=1;
    long count=0;
        while(j<n){
        if(arr[j]-arr[i]>=k){
            count+=(n-j);
            i++;
            j++;
        }
        else if(arr[j]-arr[i]<k){
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}