#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
struct node{
  int even;
 int odd;
};
void buildtree(int*arr,node*tree,int start,int end,int treeindex){
 if(start==end){
 if(arr[start]%2!=0){
 tree[treeindex].odd=1;
}else{
      tree[treeindex].even=1;
}
return;
}
int mid=(start+end)/2;
buildtree(arr,tree,start,mid,2*treeindex);
buildtree(arr,tree,mid+1,end,2*treeindex+1);
tree[treeindex].even=tree[2*treeindex].even+tree[2*treeindex+1].even;
tree[treeindex].odd=tree[2*treeindex].odd+tree[2*treeindex+1].odd;
}
void updateTree(int *arr,node *tree,int start,int end,int treeindex,int index,int value){
if(start==end){
arr[index]=value;
if(value%2!=0){
 tree[treeindex].odd=1;
tree[treeindex].even=0;
}else{
   tree[treeindex].even=1;
tree[treeindex].odd=0;
}
return;
}

int mid=(start+end)/2;
 if(index>mid){
 updateTree(arr,tree,mid+1,end,2*treeindex+1,index,value);
}else{
    updateTree(arr,tree,start,mid,2*treeindex,index,value);
}
tree[treeindex].even=tree[2*treeindex].even+tree[2*treeindex+1].even;
tree[treeindex].odd=tree[2*treeindex].odd+tree[2*treeindex+1].odd;
}
node query(node*tree,int start,int end,int treeindex,int left,int right)
{ 
if(start>right||end<left){
  node ans;
ans.even=0;
ans.odd=0;
return ans;
}
if(start>=left&&end<=right){
 node ans;
ans.even=tree[treeindex].even;
ans.odd=tree[treeindex].odd;
return ans;
}
int mid=(start+end)/2;
node leftans=query(tree,start,mid,2*treeindex,left,right);
node rightans=query(tree,mid+1,end,2*treeindex+1,left,right);
node finalans;
finalans.even=leftans.even+rightans.even;
finalans.odd=leftans.odd+rightans.odd;
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
node*tree=new node[4*n]();
buildtree(arr,tree,0,n-1,1);
int q;
cin>>q;
int choice,start,end;
for(int i=0;i<q;i++){
 cin>>choice;
if(choice==1){
 cin>>start>>end;
cout<<query(tree,0,n-1,1,start-1,end-1).even<<endl;
}
else if(choice==2){
  cin>>start>>end;
   cout<<query(tree,0,n-1,1,start-1,end-1).odd<<endl;
}
else{
cin>>start>>end;
 updateTree(arr,tree,0,n-1,1,start-1,end);

}
}
delete[]arr;
delete[]tree;
 return 0;
}