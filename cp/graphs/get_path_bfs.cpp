#include<bits/stdc++.h>
using namespace std;
vector<int>*getpath(int**edges,int n,int sv,int ev,vector<bool>&visited){
 queue<int> pending;
unordered_map<int,int> mp;
visited[sv]=true;
pending.push(sv);
bool flag=false;
while(!pending.empty()&&!flag){
int front=pending.front();
pending.pop();
for(int i=0;i<n;i++){
 if(edges[front][i]==1&&!visited[i]){
 pending.push(i);
visited[i]=true;
mp[i]=front;
if(i==ev){
 flag=true;
break;
}

}
}




}
  if(!flag){
 return NULL;
}
else{
 vector<int>*output=new vector<int>();
output->push_back(ev);
int current=ev;
while(current!=sv){
 current=mp[current];
output->push_back(current);
}
return output;
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
 int f,s;cin>>f>>s;
edges[f][s]=1;
edges[s][f]=1;
}
vector<bool> visited(n,false);
int sv,ev;
cin>>sv>>ev;
vector<int>*output=getpath(edges,n,sv,ev,visited);
if(output!=NULL){
 for(int i=0;i<output->size();i++){
 cout<<output->at(i)<<" ";
}
}
 return 0;
}