#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
typedef long long ll;
ll dp[101][101][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    ll*arr=new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll total=0;
    ll *add=new ll[n];
    add[0]=arr[0];
    for(int i=1;i<n;i++){
        add[i]=arr[i]+arr[i-1];
    }
    ll sum_till=arr[0];
    for(int i=1;i<k;i++){
        total+=(i*arr[i])-sum_till;
        sum_till += arr[i];
    }
    ll mincost=total;
    for(int i=k;i<n;i++){
        sum_till-=add[i-k];
        ll totalsum=(total-2*sum_till)+((k-1)*arr[i-k])+((k-1)*arr[i]);
        mincost=min(mincost,totalsum);
        total=totalsum;
    }
    cout<<mincost<<endl;   
}

