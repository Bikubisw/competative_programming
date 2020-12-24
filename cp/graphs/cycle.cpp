#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v){
 int **edges=new int*[n+1];
for(int i=0;i<=n;i++){
 edges[i]=new int[n+1];
for(int j=0;j<=n;j++){
 edges[i][j]=0;
}
}
for(int i=0;i<m;i++){
 edges[u[i]][v[i]]=1;
edges[v[i]][u[i]]=1;
}
int count=0;
for(int i=1;i<=n;i++){
 for(int j=1;j<=n;j++){
 if(edges[i][j]==1){
 for(int k=1;k<=n;k++){
 if(i==k){
 continue;
}
if(edges[j][k]==1&&edges[i][k]==1){
 count++;
}
}
}
}
}
return count/6;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n,m;
vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
 return 0;
}