#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>*edges,vector<bool>&visited,int sv){
visited[sv]=true;
for(int i=0;i<edges[sv].size();i++){
 if(!visited[edges[sv][i]]){
 dfs(edges,visited,edges[sv][i]);
}
}
}
bool trans(vector<int>*edges,int n,int t){
 vector<bool> visited(n,false);
dfs(edges,visited,1);
if(visited[t]){
 return true;
}
return false;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,t;
cin>>n>>t;
vector<int> arr(n);
for(int i=1;i<n;i++){
 cin>>arr[i];
}
vector<int>*edges=new vector<int>[n+1];
for(int i=1;i<n;i++){
 edges[i].push_back(i+arr[i]);
}
if(trans(edges,n,t)){
 cout<<"YES"<<endl;
}else{
  cout<<"NO"<<endl;
}
 delete[] edges;
 return 0;
}