#include<bits/stdc++.h>
using namespace std;
int getvertex(bool* visited,int* dist,int n){
 int minvertex=-1;
for(int i=0;i<n;i++){
 if(!visited[i]&&(minvertex==-1||dist[minvertex]>dist[i])){
 minvertex=i;
}
}
return minvertex;
}
void dijkstra(int **edges,int n){
bool*visited=new bool[n]();
int *dist=new int[n];
for(int i=0;i<n;i++){
dist[i]=INT_MAX;
}
dist[0]=0;
for(int i=0;i<n-1;i++){
 int minvertex=getvertex(visited,dist,n);
visited[minvertex]=true;
for(int j=0;j<n;j++){
  if(edges[minvertex][j]!=0&&!visited[j]){
 int currd=dist[minvertex]+edges[minvertex][j];
if(currd<dist[j]){
 dist[j]=currd;
}
}

}

}
for(int i=0;i<n;i++){

 cout<<i<<" "<<dist[i]<<endl;
}
delete[] dist;
delete[] visited;

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
dijkstra(edges,n);
for(int i=0;i<n;i++){

 delete[] edges[i];
}
delete[] edges;
 return 0;
}