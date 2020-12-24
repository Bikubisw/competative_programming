#include<bits/stdc++.h>
using namespace std;
int bfs(vector<int>*edges,int n,vector<bool>&visited,int sv){
vector<int> level(n+1);
queue<int> pending;
pending.push(sv);
visited[sv]=true;
level[sv]=0;
while(!pending.empty()){
 int front=pending.front();
pending.pop();
for(int i=0;i<edges[front].size();i++){
 if(!visited[edges[front][i]]){
 pending.push(edges[front][i]);
 visited[edges[front][i]]=true;
level[edges[front][i]]=level[front]+1;
}
}
}
return level[n];

}
int count(vector<int>* edges,int n){
vector<bool> visited(n+1,false);
return bfs(edges,n,visited,1);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
 int n,e;
cin>>n>>e;
vector<int>*edges=new vector<int>[n+1];
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f].push_back(s);
edges[s].push_back(f);
}

cout<<count(edges,n)<<endl;
delete[] edges;
}

 return 0;
}