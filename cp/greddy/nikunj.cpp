#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
 int*arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];

}
sort(arr,arr+n,greater<int>());
long long ans=0;
for(int i=0;i<n;i++){
 ans+=(arr[i]*(1<<i));
ans=ans%MOD;
}
cout<<ans<<endl;
 return 0;

}