#include<bits/stdc++.h>
using namespace std;
class Edges{
  public:
    int src;
  int des;
int wei;
};
bool compare(Edges a,Edges b){
return a.wei<b.wei;
}
int getpoint(int v,int *parent){
if(parent[v]==v){
 return v;
}
return getpoint(parent[v],parent);

}
pair<int,int> countit(Edges*input,int n,int e,int air_cost){
int*parent=new int[n+1];
for(int i=1;i<=n;i++){
 parent[i]=i;
}
int count=0;
int i=0;
 long ans=0;
while(i<e){
 Edges current=input[i];
if(current.wei<air_cost){
 int srcpoint=getpoint(current.src,parent);
int despoint=getpoint(current.des,parent);
if(srcpoint!=despoint){
 ans+=current.wei;
parent[srcpoint]=despoint;
}
}
i++;
}

int count1=0;
for(int i=1;i<=n;i++){
 if(parent[i]==i){
 count1++;
}
}
ans+=count1*air_cost;
pair<int,int> smallans;
smallans.first=ans;
smallans.second=count1;
delete[] parent;
return  smallans;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
int num=1;
while(t--){
 int n,e,air_cost;
cin>>n>>e>>air_cost;
Edges* input=new Edges[e];
for(int i=0;i<e;i++){
int s,d,w;
cin>>s>>d>>w;
input[i].src=s;
input[i].des=d;
input[i].wei= w;
}
sort(input,input+e,compare);
pair<int,int> ans=countit(input,n,e,air_cost);
cout<<"Case "<<"#"<<num<<":"<<" "<<ans.first<<" "<<ans.second<<endl;
num++;
delete[] input;
}
return 0;
}