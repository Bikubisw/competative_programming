#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
void buildtree(vector<int>arr,int *tree,int start,int end,int treeindex){
if(start==end){
 tree[treeindex]=arr[start];
return;
}
int mid=(start+end)/2;
buildtree(arr,tree,start,mid,2*treeindex);
buildtree(arr,tree,mid+1,end,2*treeindex+1);
tree[treeindex]=((tree[2*treeindex]*((1<<(end-mid))%3))%3+tree[2*treeindex+1]%3)%3;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
string s;
cin>>s;
vector<int>arr(n);
for(int i=0;i<n;i++){
 arr[i]=s[i]-48;
}
int*tree=new int[4*n]();
buildtree(arr,tree,0,n-1,1);
for(int i=1;i<4*n;i++){
 cout<<tree[i]<<" ";
}
 return 0;

}