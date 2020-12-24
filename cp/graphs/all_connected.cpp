#include<bits/stdc++.h>
using namespace std;
void printdfs(int** edges,int n,int sv,vector<bool>&visited,vector<int>&small){
    small.push_back(sv);
visited[sv]=true;
for(int i=0;i<n;i++){

if(!visited[i]&&edges[sv][i]==1&&i!=sv){
 printdfs(edges,n,i,visited,small);
}
}
}
vector<vector<int>>connected(int**edges,int n){
vector<vector<int>>output;
vector<bool>visited(n,false);
for(int i=0;i<n;i++){
 if(!visited[i]){
 vector<int>small;
printdfs(edges,n,i,visited,small);
output.push_back(small);
}
}
return output;

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
vector<vector<int>>output=connected(edges,n);
for(int i=0;i<output.size();i++){
 sort(output[i].begin(),output[i].end());
}
for(int i=0;i<output.size();i++){
 for(int j=0;j<output[i].size();j++){
 cout<<output[i][j]<<" ";
}
cout<<endl;

}

 return 0;
}