#include<bits/stdc++.h>
using namespace std;
void initialize(bool** visited,int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=false;
		}
	}
}
int dfs(char**edges,int n,int i,int j,bool** visited){
 visited[i][j]=true;
 if(edges[i][j]=='0'){
 return 0;
}
int count=0;
if(j+1<n&&edges[i][j+1]=='1'&&!visited[i][j+1]){
 count+=dfs(edges,n,i,j+1,visited);
}
if(i-1>=0&&edges[i-1][j]=='1'&&!visited[i-1][j]){
 count+=dfs(edges,n,i-1,j,visited);
}
if(j+1<n&&edges[i][j+1]=='1'&&!visited[i][j+1]){
 count+=dfs(edges,n,i,j+1,visited);
}
if(j-1>=0&&edges[i][j-1]=='1'&&!visited[i][j-1]){
 count+=dfs(edges,n,i,j-1,visited);
}
if(i+1<n&&edges[i+1][j]=='1'&&!visited[i+1][j]){
 count+=dfs(edges,n,i+1,j,visited);
}
return 1+count;

}
int solve(char**edges,int n){
 bool**visited=new bool*[n];
for(int i=0;i<n;i++){
 visited[i]=new bool[n];
for(int j=0;j<n;j++){
 visited[i][j]=false;
}
}
int max=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
int count=0;
 if(edges[i][j]=='1'&&!visited[i][j]){
     count=dfs(edges,n,i,j,visited);
}
if(count>max){
 max=count;
}
initialize(visited,n);
}
}
return max;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n;
cin>>n;
char **edges=new char*[n];
for(int i=0;i<n;i++){
 edges[i]=new char[n];
for(int j=0;j<n;j++){
 cin>>edges[i][j];
}
}
cout<<solve(edges,n)<<endl;

 return 0;
}