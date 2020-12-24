#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll *arr=new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> output;
    for(int i=0;i<n;i++){
      arr[i]=arr[i]-i;
      if(arr[i]<=0){
          cout<<i+1<<endl;
          break;
      }
    }

}