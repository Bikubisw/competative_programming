#include<bits/stdc++.h>
using namespace std;
void dfs(int **edges,int n,int sv,vector<bool>&visited){
 visited[sv]=true;
for(int i=0;i<n;i++){
 if(!visited[i]&&edges[sv][i]==1&&i!=sv){
 dfs(edges,n,i,visited);
}
}
}
bool connected(int** edges,int n){
vector<bool>visited(n,false);
 dfs(edges,n,0,visited);
for(int i=0;i<n;i++){
 if(visited[i]==false){
 return false;
}
}
return true;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int n,e;
cin>>n>>e;
int **edges=new int*[n];
for(int i=0;i<n;i++){
 edges[i]=new int[n];
for(int j=0;j<n;j++){
 edges[i][j]=0;
}
}
for(int i=0;i<e;i++){
 int f,s;cin>>f>>s;
edges[f][s]=1;
edges[s][f]=1;
}
if(connected(edges,n)){
 cout<<"true"<<endl;
}else{
 cout<<"false"<<endl;
}
 return 0;
}