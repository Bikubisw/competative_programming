#include<bits/stdc++.h>
using namespace std;
vector<int>* getpath(vector<vector<int>>edges,int n,int sv,int ev,vector<bool> visited){
 if(sv==ev){
 vector<int>*output=new vector<int>();
output->push_back(ev);
return output;
}
visited[sv]=true;
for(int i=0;i<n;i++){
 if(edges[sv][i]==1&&!visited[i]){
 vector<int>*small=getpath(edges,n,i,ev,visited);
 if(small!=NULL){
 small->push_back(sv);
return small;
}
}
}
return NULL;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,e;
cin>>n>>e;
vector<vector<int>>edges(n,vector<int>(n,0));
for(int i=0;i<n;i++){
 int f,s;
cin>>f>>s;
edges[f][s]=1;
edges[s][f]=1;
}
int sv,ev;
cin>>sv>>ev;
vector<bool> visited(n,false);
vector<int>*output=getpath(edges,n,sv,ev,visited);
if(output!=NULL){
for(int i=0;i<output->size();i++){
 cout<<output->at(i)<<" ";
}
}
 return 0;
}