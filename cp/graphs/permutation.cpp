#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>*edges,int sv,vector<bool>&visited,unordered_set<int>*output){
visited[sv]=true;
output->insert(sv);
for(int i=0;i<edges[sv].size();i++){
int next=edges[sv][i];
 if(!visited[next]){
 dfs(edges,next,visited,output);
}
}
}
unordered_set<unordered_set<int>*>* getcomponent(vector<int>*edges,int n){
vector<bool> visited(n,false);
unordered_set<unordered_set<int>*>*finaloutput=new unordered_set<unordered_set<int>*>();
for(int i=0;i<n;i++){
 if(!visited[i]){
   unordered_set<int>*output=new unordered_set<int>();
  dfs(edges,i,visited,output);
finaloutput->insert(output);
}
}
return finaloutput;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int t;
cin>>t;
while(t--){
 int n,e;
cin>>n>>e;
vector<int> p(n);
vector<int> q(n);
for(int i=0;i<n;i++){
cin>>p[i];
}
for(int i=0;i<n;i++){
cin>>q[i];
}
vector<int>*edges=new vector<int>[n];
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f-1].push_back(s-1);
edges[s-1].push_back(f-1);
}
unordered_set<unordered_set<int>*>*components=getcomponent(edges,n);
unordered_set<unordered_set<int>*>:: iterator it1=components->begin();
bool flag=true;
while(it1!=components->end()){
unordered_set<int>*component=*it1;
unordered_set<int> s1,s2;
unordered_set<int>::iterator it2=component->begin();
while(it2!=component->end()){
s1.insert(p[*it2]);
s2.insert(q[*it2]);
  it2++;
}
if(s1!=s2){
flag=false;
}
it1++;
}
if(flag){
 cout<<"YES"<<endl;
}else{
 cout<<"NO"<<endl;
}
}
return 0;
}
