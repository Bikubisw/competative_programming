#include<bits/stdc++.h>
using namespace std; 
void initialize(bool**visited,int n,int m){
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 visited[i][j]=false;
}

}
}
bool dfs(vector<vector<char>>edges,int n,int m,int i,int j,bool**visited,string s){
if(s.length()==0){
 return true;
}
visited[i][j]=true;
bool ans=false;
if(i-1>=0&&j-1>=0&&!visited[i-1][j-1]&&edges[i-1][j-1]==s[0]){
ans=ans||dfs(edges,n,m,i-1,j-1,visited,s.substr(1));
}
if(i-1>=0&&!visited[i-1][j]&&edges[i-1][j]==s[0]){
  ans=ans||dfs(edges,n,m,i-1,j,visited,s.substr(1));
}
if(i-1>=0&&j+1<m&&!visited[i-1][j+1]&&edges[i-1][j+1]==s[0]){
  ans=ans||dfs(edges,n,m,i-1,j+1,visited,s.substr(1));
}
if(j-1>=0&&!visited[i][j-1]&&edges[i][j-1]==s[0]){
   ans=ans||dfs(edges,n,m,i,j-1,visited,s.substr(1));
}
if(j+1<m&&!visited[i][j+1]&&edges[i][j+1]==s[0]){
   ans=ans||dfs(edges,n,m,i,j+1,visited,s.substr(1));
}if(i+1<n&&j-1>=0&&!visited[i+1][j-1]&&edges[i+1][j-1]==s[0]){
  ans=ans||dfs(edges,n,m,i+1,j-1,visited,s.substr(1));
}if(i+1<n&&!visited[i+1][j]&&edges[i+1][j]==s[0]){
ans=ans||dfs(edges,n,m,i+1,j,visited,s.substr(1));
}
if(i+1<n&&j+1<m&&!visited[i+1][j+1]&&edges[i+1][j+1]==s[0]){
ans=ans||dfs(edges,n,m,i+1,j+1,visited,s.substr(1));
}
 return ans;
}  
int  solve( vector<vector<char>>edges,int n,int m){
string s="CODINGNINJA";
bool**visited=new bool*[n];
for(int i=0;i<n;i++){
 visited[i]=new bool[m];
}
initialize(visited,n,m);
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 if(edges[i][j]=='C'){
 bool ans=dfs(edges,n,m,i,j,visited,s.substr(1));
if(ans){
 return 1;
}
initialize(visited,n,m);

}
}

}

 return 0;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
 vector<vector<char>>edges(n,vector<char>(m));
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 cin>>edges[i][j];
}
}
cout<<solve(edges,n,m)<<endl;
}