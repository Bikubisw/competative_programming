#include<bits/stdc++.h>
using namespace std;
void print(int**edges,int n,int sv,vector<bool>&visited){
cout<<sv<<endl;
visited[sv]=true;
for(int i=0;i<n;i++){
   if(i==sv){
 continue;
}
if(edges[sv][i]==1){
if(visited[i]){
 continue;
}
 print(edges,n,i,visited);
}
}

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
 int first,second;
cin>>first>>second;
 edges[first][second]=1;
edges[second][first]=1;
}
vector<bool> visited(n,false);
print(edges,n,0,visited);

 return 0;
}