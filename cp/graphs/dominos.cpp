#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>*edges,int sv,bool*visited,stack<int> &finishVertices){
visited[sv]=true;
for(int i=0;i<edges[sv].size();i++){
 if(!visited[edges[sv][i]]){
 dfs(edges,edges[sv][i],visited,finishVertices);
}
}
finishVertices.push(sv);
}
void dfs2(vector<int>*edgesT,int sv,bool*visited){
visited[sv]=true;
for(int i=0;i<edgesT[sv].size();i++){
 if(!visited[edgesT[sv][i]]){
 dfs2(edgesT,edgesT[sv][i],visited);
}

}
}
int getcomponents(vector<int>*edges,int n){
bool*visited=new bool[n];
for(int i=0;i<n;i++){
 visited[i]=false;
}
stack<int> finishVertices;
for(int i=0;i<n;i++){
 if(!visited[i]){
 dfs(edges,i,visited,finishVertices);
}
}
for(int i=0;i<n;i++){
 visited[i]=false;
}
int count=0;
while(finishVertices.size()!=0){
 int element=finishVertices.top();
finishVertices.pop();
 if(!visited[element]){
 dfs2(edges,element,visited);
count++;
}
}
delete[] visited;
return count;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int t;
cin>>t;
while(t--){
int n,e;
cin>>n>>e;
vector<int>*edges=new vector<int>[n];
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f-1].push_back(s-1);
}
int count=getcomponents(edges,n);
cout<<count<<endl;
}
 return 0;
}