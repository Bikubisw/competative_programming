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
Edges* kruskal(Edges*input,int n,int e){
Edges*output=new Edges[n-1];
int *parent=new int[n];
for(int i=0;i<n;i++){
 parent[i]=i;
}
int count=0;
int i=0;
while(count<n-1){
  Edges currentedge=input[i];
 int srcpoint=getpoint(currentedge.src,parent);
int despoint=getpoint(currentedge.des,parent);
if(srcpoint!=despoint){
output[count]=currentedge;
 count++;
parent[srcpoint]=despoint;
}

i++;
}
return output;

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,e;
cin>>n>>e;
Edges*input=new Edges[e];
for(int i=0;i<e;i++){
 int s,d,w;
cin>>s>>d>>w;
input[i].src=s;
input[i].des=d;
input[i].wei=w;
}
sort(input,input+e,compare);
Edges*output=kruskal(input,n,e);
for(int i=0;i<n-1;i++){
 if(output[i].src<output[i].des){
cout<<output[i].src<<" "<<output[i].des<<" "<<output[i].wei<<endl;
}else{
  cout<<output[i].des<<" "<<output[i].src<<" "<<output[i].wei<<endl;
}
}


 return 0;
}