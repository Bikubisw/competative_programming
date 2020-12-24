#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    ll *arr=new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    queue<ll> q;
    int endpointer=n-1;
    int count=0;
    while(m--){
        int num;
        cin>>num;
        ll ans;
        for(;count<num;count++){
            if(endpointer>=0&&(q.empty()||arr[endpointer]>=q.front())){
                ans=arr[endpointer];
                endpointer--;
            }else{
                ans=q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }

    

    return 0;
}