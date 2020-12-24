#include<bits/stdc++.h>
//coci 13 contest problem
using namespace std;
bool compare(pair<int,int>a,pair<int,int> b){
if(a.second==b.second){
 return a.first<b.first;

}
 return a.second>b.second;

}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
 int n,k;
cin>>n>>k;
vector<pair<int,int>> arr(n);
for(int i=0;i<n;i++){
 cin>>arr[i].first;
 cin>>arr[i].second;
}
sort(arr.begin(),arr.end(),compare);
multiset<int> bag;
int weight;
for(int i=0;i<k;i++){
 cin>>weight;
 bag.insert(weight);                                                              
}
long ans=0;
for(int i=0;i<n;i++){
 if(bag.empty()){
 break;
}else if(bag.lower_bound(arr[i].first)!=bag.end()){
ans+=arr[i].second;
bag.erase(bag.lower_bound(arr[i].first));
}

}
cout<<ans<<endl;


 return 0;

}