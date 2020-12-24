#include<bits/stdc++.h>
using namespace std;
void printdfs(int** edges,int n,int sv,vector<bool>&visited){
visited[sv]=true;
for(int i=0;i<n;i++){

if(!visited[i]&&edges[sv][i]==1&&i!=sv){
 printdfs(edges,n,i,visited);
}
}
}
int count(int **edges,int n){
 vector<bool>visited(n,false);
int count=0;
for(int i=0;i<n;i++){
 if(!visited[i]){
printdfs(edges,n,i,visited);
count++;
}
}
return count;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,m;
cin>>n>>m;
vector<int>u,v;
for(int i=0;i<m;i++){
int x;
cin>>x;
u.push_back(x);
}
for(int i=0;i<m;i++){
 int x;
cin>>x;
v.push_back(x);
}
int **edges=new int*[n];
for(int i=0;i<n;i++){
 edges[i]=new int[n];
for(int j=0;j<n;j++){
 edges[i][j]=0;
}
}
for(int i=0;i<m;i++){

 edges[u[i]-1][v[i]-1]=1;
 edges[v[i]-1][u[i]-1]=1;

}
cout<<count(edges,n)<<endl;


 return 0;
}