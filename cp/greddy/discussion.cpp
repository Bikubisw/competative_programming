#include<bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
  int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i=0;i<n;i++){
 cin>>arr[i];
}
sort(arr.begin(),arr.end());
int big=arr[n-1]-k;
int small=arr[0]+k;
if(small>big){
 swap(small,big);
}
int ans=(big-small);
for(int i=1;i<n-1;i++){
 int sub=arr[i]-k;
int add=arr[i]+k;
if(sub>=small||add<=big){
 continue;
}
else if(big-sub<=add-small){
 small=sub;
}
else{
 big=add;
}
}
cout<<min(ans,(big-small))<<endl;

 return 0;

}