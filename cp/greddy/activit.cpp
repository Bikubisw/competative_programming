#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
 return a.second<b.second;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
 int n;
cin>>n;
vector<pair<int,int>>arr(n);
for(int i=0;i<n;i++){
 cin>>arr[i].first;
cin>>arr[i].second;

}
sort(arr.begin(),arr.end(),compare);
int end=arr[0].second;
int count=1;
for(int i=1;i<n;i++){
 if(arr[i].first>=end){
 count++;
end=arr[i].second;
}
}
cout<<count<<endl;
 return 0;

}