#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int c,ll *arr,int n,ll distance){
    int count=1;
    ll pos=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=distance){
            pos=arr[i];
            count++;
        }
        if(count==c){
            return true;
        }
    }
    return false;
}
int main(){
int t;
cin>>t;
while(t--){
    int n,c;
    cin>>n>>c;
    ll *arr=new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll start=0;
    ll end=arr[n-1]-arr[0];
    ll ans=-1;
    while(start<=end){
        ll mid=start+(end-start)/2;
        if(check(c,arr,n,mid)){
            ans=mid;
            start=mid+1;

        }else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;
}
    return 0;
}