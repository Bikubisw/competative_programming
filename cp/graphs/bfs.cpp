#include<bits/stdc++.h>
using namespace std;       
void print_bfs(vector<vector<int>>edges,int n,int sv,vector<bool>&visited){
queue<int> pendingnodes;
pendingnodes.push(sv);
visited[sv]=true;
while(!pendingnodes.empty()){
 int current=pendingnodes.front();
pendingnodes.pop();
cout<<current<<" ";
for(int i=0;i<n;i++){
 if(edges[current][i]==1&&!visited[i]){
 pendingnodes.push(i);
 visited[i]=true;
}
}
}
}
void bfs(vector<vector<int>>edges,int n){
 vector<bool> visited(n,false);
for(int i=0;i<n;i++){
 if(!visited[i]){
  print_bfs(edges,n,i,visited);
}
}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,e;
cin>>n>>e;
vector<vector<int>>edges(n,vector<int>(n,0));
for(int i=0;i<e;i++){
int f,s;
cin>>f>>s;
edges[f][s]=1;
edges[s][f]=1;
}
bfs(edges,n);
 return 0;
}