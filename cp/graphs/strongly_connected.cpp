#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>*edges,int sv,unordered_set<int>&visited,stack<int> &finishVertices){
visited.insert(sv);
for(int i=0;i<edges[sv].size();i++){
 if(visited.count(edges[sv][i])==0){
 dfs(edges,edges[sv][i],visited,finishVertices);
}
}
finishVertices.push(sv);
}
void dfs2(vector<int>*edgesT,int sv,unordered_set<int>& visited,unordered_set<int>*component){
visited.insert(sv);
component->insert(sv);
for(int i=0;i<edgesT[sv].size();i++){
 if(visited.count(edgesT[sv][i])==0){
 dfs2(edgesT,edgesT[sv][i],visited,component);
}

}
}
unordered_set<unordered_set<int>*>*getcomponents(vector<int>*edges,vector<int>*edgesT,int n){
unordered_set<int> visited;
stack<int> finishVertices;
for(int i=0;i<n;i++){
 if(visited.count(i)==0){
 dfs(edges,i,visited,finishVertices);
}
}
unordered_set<unordered_set<int>*>*output=new unordered_set<unordered_set<int>*>();
visited.clear(); 
while(finishVertices.size()!=0){
 int element=finishVertices.top();
finishVertices.pop();
 if(visited.count(element)==0){
unordered_set<int>*component=new unordered_set<int>();
 dfs2(edgesT,element,visited,component);
   output->insert(component);
}


}
return output;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,e;
cin>>n>>e;
vector<int>*edges=new vector<int>[n];
vector<int>*edgesT=new vector<int>[n];
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f-1].push_back(s-1);
edgesT[s-1].push_back(f-1);
}
unordered_set<unordered_set<int>*>*components=getcomponents(edges,edgesT,n);
unordered_set<unordered_set<int>*>::iterator it1= components->begin();
 while(it1!=components->end()){
unordered_set<int>*component=*it1;
unordered_set<int>:: iterator it2=component->begin();
while(it2!=component->end()){
cout<<*it2+1<<" ";
 it2++;
}
cout<<endl;
it1++;
}



delete components;
delete[] edges;
delete[] edgesT; 
 return 0;
}