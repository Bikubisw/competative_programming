#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadnanealgo (int *arr,int n){
    ll curr=0;
    ll max=INT_MIN;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr>max){
            max=curr;
        }
        if(curr<0){
            curr=0;
        }
    }
    return max;

}
ll kadnane(int *arr, int n, int k)
{
    ll kadnanae_sum=kadnanealgo(arr,n);
    if(k==1){
        return kadnanae_sum;
    }
    ll curr_prefix_sum=0;
    ll max_prefix_sum=INT_MIN;
    ll curr_suffix_sum = 0;
    ll max_suffix_sum = INT_MIN;
    for(int i=0;i<n;i++){
        curr_prefix_sum+=arr[i];
        max_prefix_sum=max(max_prefix_sum,curr_prefix_sum);
    }
    ll totalsum=curr_prefix_sum;
    for(int i=n-1;i>=0;i--){
        curr_suffix_sum+=arr[i];
        max_suffix_sum=max(max_suffix_sum,curr_suffix_sum);
    }
    ll ans;
    if(totalsum>=0){
        ans=max(max_prefix_sum+max_suffix_sum+((k-2)*totalsum),kadnanae_sum);
    }
    else{
        ans=max(max_prefix_sum+max_suffix_sum,kadnanae_sum);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int t,k;
        cin>>t>>k;
        int *arr=new int[t];
        for(int i=0;i<t;i++){
            cin>>arr[i];
        }
        cout << kadnane(arr,t,k)<<endl;
    }
}