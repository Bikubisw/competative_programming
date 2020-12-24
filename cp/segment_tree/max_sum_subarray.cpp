#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
struct node{
  int sum;
 int maxsum;
int bestpresum;
int bestsuffsum;
};
void buildtree(int*arr,node*tree,int start,int end,int treenode){
if(start==end){
 tree[treenode].sum=arr[start];
 tree[treenode].maxsum=arr[start];
 tree[treenode].bestpresum=arr[start];
 tree[treenode].bestsuffsum=arr[start];
  return;
}
int mid=(start+end)/2;
  buildtree(arr,tree,start,mid,2*treenode+1);
buildtree(arr,tree,mid+1,end,2*treenode+2);
node left=tree[2*treenode+1];
node right=tree[2*treenode+2];
tree[treenode].sum=left.sum+right.sum;
tree[treenode].bestpresum=max(left.bestpresum,left.sum+right.bestpresum);
tree[treenode].bestsuffsum=max(right.bestsuffsum,right.sum+left.bestsuffsum);
tree[treenode].maxsum=max(left.maxsum,max(right.maxsum,max(left.sum+right.bestpresum,max(right.sum+left.bestsuffsum,left.bestsuffsum+right.bestpresum))));
}
node query(node*tree,int start,int end,int treenode,int lefty,int righty){
if(start>righty||end<lefty){
return {-100000, -100000, -100000, -100000};
}
if(start>=lefty&&end<=righty){
 return tree[treenode];
}
int mid=(start+end)/2;
node left=query(tree,start,mid,2*treenode+1,lefty,righty);
node right=query(tree,mid+1,end,2*treenode+2,lefty,righty);
node finalans;
finalans.sum=left.sum+right.sum;
finalans.bestpresum=max(left.bestpresum,left.sum+right.bestpresum);
finalans.bestsuffsum=max(right.bestsuffsum,right.sum+left.bestsuffsum);
finalans.maxsum=max(left.maxsum,max(right.maxsum,max(left.sum+right.bestpresum,max(right.sum+left.bestsuffsum,left.bestsuffsum+right.bestpresum))));
return finalans;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
 int n;
cin>>n;
int*arr=new int[n];
   for(int i=0;i<n;i++){
 cin>>arr[i];
}
node*tree=new node[4*n];
buildtree(arr,tree,0,n-1,0);
int q;
cin>>q;
int left,right;
for(int i=0;i<q;i++){
cin>>left>>right;
 node ans=query(tree,0,n-1,0,left-1,right-1);
cout<<ans.maxsum<<endl;
} 
 return 0;

}
