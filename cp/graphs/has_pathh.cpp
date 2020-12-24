#include<bits/stdc++.h>
using namespace std;
bool haspath(vector<vector<int>>edges,int n,int sv,int end,vector<bool>&visited){
queue<int>pendingnodes;
pendingnodes.push(sv);
visited[sv]=true;
while(!pendingnodes.empty()){
int current=pendingnodes.front();
pendingnodes.pop();
for(int i=0;i<n;i++){
 if(edges[current][i]==1&&!visited[i]){
if(i==end){
return true;
}
 pendingnodes.push(i);
visited[i]=true;
}
}
}
return false;
}
bool dfs(vector<vector<int>>edges,int n,int start,int end){
 if(edges[start][end]==1){
 return true;
}
vector<bool>visited(n,false);
return haspath(edges,n,start,end,visited);

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
int start,end;
cin>>start>>end;
if(dfs(edges,n,start,end)){
 cout<<"true"<<endl;

}else{
   cout<<"false"<<endl;
}

 return 0;
}