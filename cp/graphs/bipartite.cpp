#include<bits/stdc++.h>
using namespace std;
bool bipartite(vector<int>*edges,int n){
if(n==0){
return true;
}
unordered_set<int> s[2];
vector<int> pending;
s[0].insert(0);
pending.push_back(0);
while(pending.size()>0){
 int current=pending.back();
pending.pop_back();
int currentset=s[0].count(current)>0?0:1;
for(int i=0;i<edges[current].size();i++){
 if(s[0].count(edges[current][i])==0&&s[1].count(edges[current][i])==0){
 s[1-currentset].insert(edges[current][i]);
pending.push_back(edges[current][i]);
}else if(s[currentset].count(edges[current][i])>0){
return false;
}
}


}
return true;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
while(true){
 int n;
cin>>n;
if(n==0){
 break;
}
int e;
cin>>e;
vector<int>*edges=new vector<int>[n];
for(int i=0;i<e;i++){
 int f,s;
cin>>f>>s;
edges[f].push_back(s);
edges[s].push_back(f);
}

bool ans=bipartite(edges,n);
if(ans){
 cout<<"Bipartite"<<endl;
}
else{
 cout<<"Not bipartite"<<endl;
}
delete[] edges;


}
 return 0;

}