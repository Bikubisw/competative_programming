#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dfs(vector<int>*edges,int n,int sv,vector<bool>&visited,vector<ll>&cost){
visited[sv]=true;
ll costvalue=cost[sv];
for(int i=0;i<edges[sv].size();i++){
 if(!visited[edges[sv][i]]){
  costvalue+=dfs(edges,n,edges[sv][i],visited,cost);
}

}
return costvalue;

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
vector<ll> cost(n+1);
for(int i=1;i<=n;i++){
 cin>>cost[i];
}
vector<bool> visited(n+1,false);
ll maximum=0;
for(int i=1;i<=n;i++){
 if(!visited[i]){
 ll current=dfs(edges,n,i,visited,cost);
if(current>maximum){
maximum=current;
}

}
}
cout<<maximum<<endl;














delete[]edges;

}



return 0;
}