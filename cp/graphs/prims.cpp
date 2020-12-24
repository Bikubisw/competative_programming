#include<bits/stdc++.h>
using namespace std;
int getvertex(int *weight,bool* visited,int n){
 int minvertex=-1;
for(int i=0;i<n;i++){
 if(!visited[i]&&(minvertex==-1||weight[minvertex]>weight[i])){
 minvertex=i;
}
}
return minvertex;
}
 void primes(int **edges,int n){
bool *visited=new bool[n]();
int *parent=new int[n];
int *weight=new int[n];
for(int i=0;i<n;i++){
 weight[i]=INT_MAX;
}
weight[0]=0;
parent[0]=-1;
for(int i=0;i<n-1;i++){
int minvertex=getvertex(weight,visited,n);
visited[minvertex]= true;
for(int j=0;j<n;j++){
 if(edges[minvertex][j]!=0&&!visited[j]){
 if(weight[j]>edges[minvertex][j]){
weight[j]=edges[minvertex][j];
parent[j]=minvertex;
}
}
}
}
for(int i=1;i<n;i++){
 if(parent[i]>i){
 cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
}else{
   cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
}
}
delete[]parent;
delete[]visited;
delete[]weight;
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
 int f,s,wei;
cin>>f>>s>>wei;
edges[f][s]=wei;
edges[s][f]=wei;
}
primes(edges,n);
for(int i=0;i<e;i++){

 delete[] edges[i];
}
delete[] edges;

 return 0;
}