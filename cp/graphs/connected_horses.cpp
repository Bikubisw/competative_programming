#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int dfs(int i,int j,bool** visited,vector<pair<int,int>>**graph){
 visited[i][j]=true;
int ans=1;
for(int k=0;k<graph[i][j].size();k++){
 int x=graph[i][j][k].first;
int y=graph[i][j][k].second;
if(!visited[x][y]){
 ans+=dfs(x,y,visited,graph);
}
}
return ans;
}
void fillgraph(vector<pair<int,int>>**graph,int**edges,int n,int m){
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 if(edges[i][j]==1){
 if(i-1>=0&&j+2<m&&edges[i-1][j+2]==1){
   graph[i][j].push_back(make_pair(i-1,j+2));
}
if(i-2>=0&&j+1<m&&edges[i-2][j+1]==1){
     graph[i][j].push_back(make_pair(i-2,j+1));;
}
if(i-2>=0&&j-1>=0&&edges[i-2][j-1]==1){
      graph[i][j].push_back(make_pair(i-2,j-1));
}
if(i+1<n&&j-2>=0&&edges[i+1][j-2]==1){
   graph[i][j].push_back(make_pair(i+1,j-2));
}
if(i+1<n&&j+2<m&&edges[i+1][j+2]==1){
      graph[i][j].push_back(make_pair(i+1,j+2));
}
if(i-1>=0&&j-2>=0&&edges[i-1][j-2]==1){
     graph[i][j].push_back(make_pair(i-1,j-2));
}
if(i+2<n&&j-1>=0&&edges[i+2][j-1]==1){
       graph[i][j].push_back(make_pair(i+2,j-1));
}
if(i+2<n&&j+1<m&&edges[i+2][j+1]==1){
    graph[i][j].push_back(make_pair(i+2,j+1));
}



}
}

}

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll *factorial=new ll[1000000];
factorial[1]=1;
for(int i=2;i<1000000;i++){
factorial[i]=(factorial[i-1]*i)%MOD;
}
 int t;
cin>>t;
while(t--){
 int n,m,h;
cin>>n>>m>>h;
int**edges=new int*[n];
for(int i=0;i<n;i++){
 edges[i]=new int[m];
for(int j=0;j<m;j++){
edges[i][j]=0;
}
}
for(int i=0;i<h;i++){
 int f,s;
cin>>f>>s;
edges[f-1][s-1]=1;
}
vector<pair<int,int>>**graph=new vector<pair<int,int>>*[n];
for(int i=0;i<n;i++){
 graph[i]=new vector<pair<int,int>>[m];
}
fillgraph(graph,edges,n,m);
bool**visited=new bool*[n];
for(int i=0;i<n;i++){
  visited[i]=new bool[m];
for(int j=0;j<m;j++){
 visited[i][j]=false;
}
}
ll ans=1;
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 if(!visited[i][j]&&edges[i][j]==1){

  ans=(ans*factorial[dfs(i,j,visited,graph)])%MOD;
}
}
}
cout<<ans<<endl;
}

 return 0;
}