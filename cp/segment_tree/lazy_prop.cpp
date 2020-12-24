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
tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}
void updatetreelazy(int *lazy,int *tree,int start,int end,int treeindex,int srange,int erange,int value){
  if(start>end){
 return;
}
if(lazy[treeindex]!=0){
tree[treeindex]+=lazy[treeindex];
if(start!=end){
 lazy[2*treeindex]+=lazy[treeindex];
 lazy[2*treeindex+1]+=lazy[treeindex];
}		
lazy[treeindex]=0;
}
if(start>erange||end<srange){
        return;
}
if(start>=srange&&end<=erange){
tree[treeindex]+=value;
if(start!=end){
 lazy[2*treeindex]+=value;
lazy[2*treeindex+1]+=value;
}
return;
}
int mid=(start+end)/2;
 updatetreelazy(lazy,tree,start,mid, 2*treeindex, srange, erange, value);
   updatetreelazy(lazy,tree,mid+1,end, 2*treeindex+1, srange, erange, value);
tree[treeindex]=min(tree[2*treeindex],tree[2*treeindex+1]);
}
int query(int*lazy,int*tree,int start,int end,int treeindex,int left,int right){
if(start>end){
  return INT_MAX;
}
if(lazy[treeindex]!=0){
  tree[treeindex]+=lazy[treeindex];
  if(start!=end){
    lazy[2 * treeindex] += lazy[treeindex];
    lazy[2 * treeindex + 1] += lazy[treeindex];
  }
  lazy[treeindex]=0;
}
if(start>right||end<left){
  return INT_MAX;
}
if(start>=left&&end<=right){
  return tree[treeindex];
}
int mid=(start+end)/2;
int option1=query(lazy,tree,start,mid,2*treeindex,left,right);
int option2=query(lazy,tree,mid+1,end,2*treeindex+1,left,right);
return min(option1,option2);

}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
int*arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}
int *tree=new int[3*n]();
int*lazy=new int[3*n]();
buildTree(arr,tree,0,n-1,1);
 updatetreelazy(lazy,tree,0,n-1,1,0,3,3);
   updatetreelazy(lazy,tree,0,n-1,1,0,1,2);
   cout<<"query"<<endl;
   cout << query(lazy, tree, 0, n - 1,1,1,4) << endl;

   return 0;

}