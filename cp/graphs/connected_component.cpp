#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>edges,vector<bool>&visited,unordered_set<int>*output,int sv){
      visited[sv]=true;
      output->insert(sv);
for(int i=0;i<edges[sv].size();i++){
 int next=edges[sv][i];
if(!visited[next]){
 dfs(edges,visited,output,next);
}
}
}
unordered_set<unordered_set<int>*>* getcomponents(vector<vector<int>>edges,int n){
vector<bool> visited(n,false);
unordered_set<unordered_set<int>*>*finaloutput=new unordered_set<unordered_set<int>*>();
for(int i=0;i<n;i++){
 if(!visited[i]){
unordered_set<int>*output=new unordered_set<int>(); 
 dfs(edges,visited,output,i);
 finaloutput->insert(output);
}
}
return finaloutput;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,e;
cin>>n>>e;
vector<vector<int>> output(n);
int f,s;
for(int i=0;i<e;i++){
cin>>f>>s;
output[f-1].push_back(s-1);
output[s-1].push_back(f-1);
}
unordered_set<unordered_set<int>*>*components=getcomponents(output,n);
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

 return 0;
}