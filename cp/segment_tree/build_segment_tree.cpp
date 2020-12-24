#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
void buildTree(int*arr,int*tree,int start,int end ,int treenode){
if(start==end){
 tree[treenode]=arr[start];
return;
}                                                                
 int mid=(start+end)/2;
buildTree(arr,tree,start,mid,2*treenode);
buildTree(arr,tree,mid+1,end,2*treenode+1);
tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
void updateTree(int *arr,int *tree,int start,int end,int treenode,int index,int value){
if(start==end){
arr[index]=value;
tree[treenode]=value;
return;
}

int mid=(start+end)/2;
 if(index>mid){
 updateTree(arr,tree,mid+1,end,2*treenode+1,index,value);
}else{
    updateTree(arr,tree,start,mid,2*treenode,index,value);
}
tree[treenode]=tree[2*treenode]+tree[2*treenode+1];

}
int query(int*tree,int start,int end,int treenode,int left,int right){
// completely outside of the range
if(start>right||end<left){
 return 0;
}
if(start>=left&&end<=right){
 return tree[treenode];
}
int mid=(start+end)/2;
int option1=query(tree,start,mid,2*treenode,left,right);
int option2=query(tree,mid+1,end,2*treenode+1,left,right);
 return option1+option2;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}
int *tree=new int[2*n];
buildTree(arr,tree,0,n-1,1);
for(int i=1;i<2*n;i++){
 cout<<tree[i]<<" ";
}
int index,value;
cin>>index>>value;
cout<<endl;
updateTree(arr,tree,0,n-1,1,index,value);
for(int i=1;i<2*n;i++){
 cout<<tree[i]<<" ";
}
cout<<endl;
cout<<query(tree,0,n-1,1,2,4)<<endl;
 return 0;

}









