#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define END pow(10,18);
bool check(ll n,ll mid){
    ll sum=0;
    ll curr=n;
    while(curr>0){
        sum+=min(mid,curr);
        curr=curr-mid;
        curr=curr-(curr/10);
    }
    if(2*sum>=n){
        return true;
    }else{
        return false;
    }
}
int main(){
    ll n;
    cin>>n;
    ll start=1;
    ll end=END;
    ll  ans=-1;
    while(start<=end){
        ll mid=(start)+(end-start)/2;
        if(check(n,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}