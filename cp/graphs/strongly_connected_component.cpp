#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>edges,int sv,stack<int>&finish,vector<bool>&visited){
visited[sv]=true;
for(int i=0;i<edges[sv].size();i++){
 if(!visited[edges[sv][i]]){
dfs(edges,edges[sv][i],finish,visited);
}
}
finish.push(sv);

}
void dfs2(vector<vector<int>>edgesT,int sv,vector<bool>&visited,vector<int>&component){
component.push_back(sv);
visited[sv]=true;

for(int i=0;i<edgesT[sv].size();i++){
 if(!visited[edgesT[sv][i]]){
dfs2(edgesT,edgesT[sv][i],visited,component);
}
}


}
vector<vector<int>> getcomponents(int n,vector<vector<int>>edges,vector<vector<int>>edgesT){
vector<bool> visited(n,false);
stack<int>finish;
for(int i=0;i<n;i++){
 if(!visited[i]){
 dfs(edges,i,finish,visited);
}
}
for(int i=0;i<n;i++){
 visited[i]=false;
}
vector<vector<int>> components;
while(!finish.empty()){
 int top=finish.top();
finish.pop();
if(!visited[top]){
 vector<int>component;
dfs2(edgesT,top,visited,component);
 components.push_back(component);
}
}
 return components;


}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,e;
cin>>n>>e;
vector<vector<int>>edges(n);
vector<vector<int>>edgesT(n);
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f-1].push_back(s-1);
edgesT[s-1].push_back(f-1);
}
vector<vector<int>>components=getcomponents(n,edges,edgesT);
for(int i=0;i<components.size();i++){
  for(int j=0;j<components[i].size();j++){
cout<<components[i][j]+1<<" ";
}
cout<<endl;
}


 return 0;
}