#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int k,ll mid,int*arr,int n){
    ll count=0;
    for(int i=0;i<n;i++){
        count+=(arr[i]/mid);
        if(count>=k){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll start=0;
        ll end=arr[n-1];
        ll ans=-1;
        while(start<=end){
            ll mid=start+(end-start)/2;
            if(check(k,mid,arr,n)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        cout<<ans<<endl;
        delete[] arr;
    }
    return 0;
}