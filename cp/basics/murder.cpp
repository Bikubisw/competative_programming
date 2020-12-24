#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(int *arr,int start,int end)
{
    int size=(end-start+1);
    int mid=(start+end)/2;
    int k=0;
    int i=start;
    int j=mid+1;
    ll output[size];
    ll count=0;
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            count+=(end-j+1)*arr[i];
            output[k++]=arr[i++];
        } else{
            output[k++]=arr[j++];
        }
    }
    while (i<=mid) {
        output[k++]=arr[i++];
    }while (j<=end) {
        output[k++]=arr[j++];
    }
    for (int i=start, m=0;i<=end;i++, m++) {
        arr[i]=output[m];
    }
return count;
}
ll murderhelper(int *arr,int start,int end){
    if(start>=end){
        return 0;
    }
        int mid=(start+end)/2;
        ll leftcount = murderhelper(arr, start, mid);
        ll rightcount = murderhelper(arr, mid+1, end);
        ll count=merge(arr, start, end);
        return leftcount+rightcount+count;
}
ll murder(int *arr,int n){
    return murderhelper(arr,0,n-1);
}
int main() {
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<murder(arr,n)<<endl;
    delete[] arr;
}
}