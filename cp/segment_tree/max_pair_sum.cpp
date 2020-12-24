#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
class node{
public:
  int maxi;
  int smaxi;
};
void builtree(int*arr,node*tree,int start,int end,int treenode){
	if(start==end){
	tree[treenode].maxi=arr[start];
	tree[treenode].smaxi=INT_MIN;
	return;	
}
int mid=(start+end)/2;
builtree(arr,tree,start,mid,2*treenode);
builtree(arr,tree,mid+1,end,2*treenode+1);
node left=tree[2*treenode];
node right=tree[2*treenode+1];
tree[treenode].maxi=max(left.maxi,right.maxi);                                  
tree[treenode].smaxi=min(max(left.maxi,right.smaxi),max(right.maxi,left.smaxi));	
}
void update(int *arr,node*tree,int start,int end,int treenode,int index,int value){
if(start==end){
 arr[index]=value;
tree[treenode].maxi=value;
tree[treenode].smaxi=INT_MIN;
return;
}

int mid=(start+end)/2;
if(index>mid){
  update(arr,tree,mid+1,end,2*treenode+1,index,value);
}else{

   update(arr,tree,start,mid,2*treenode,index,value);
}
 node left=tree[2*treenode];
  node right=tree[2*treenode+1];
   tree[treenode].maxi=max(left.maxi,right.maxi); 
 tree[treenode].smaxi=min(max(left.maxi,right.smaxi),max(right.maxi,left.smaxi));	                                
}
node query(node*tree,int start,int end,int treenode,int left,int right){
  if(start>right||end<left){
   node ans;
   ans.maxi=INT_MIN;
   ans.smaxi=INT_MIN;
   return ans;
}
if(start>=left&&end<=right){
 return tree[treenode];
}
int mid=(start+end)/2;
node option1=query(tree,start,mid,2*treenode,left,right);
node option2=query(tree,mid+1,end,2*treenode+1,left,right);
node finalans;
finalans.maxi=max(option1.maxi,option2.maxi);
finalans.smaxi=min(max(option1.maxi,option2.smaxi),max(option1.smaxi,option2.maxi));
return finalans;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int n;
cin>>n;
int*arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}
node*tree=new node[3*n];
builtree(arr,tree,0,n-1,1);
int q;
cin>>q;
int left,right;
char c;
for(int i=0;i<q;i++){
 cin>>c>>left>>right;
if(c=='Q'){
node ans= query(tree,0,n-1,1,left-1,right-1);
cout<<ans.maxi+ans.smaxi<<endl;
}else{
 update(arr,tree,0,n-1,1,left-1,right);
}

}


return 0;

}