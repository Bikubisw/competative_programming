#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
class node{
  public:
int first;
int second;
int index;
};
node* buildtree(node**arr,node**tree,int start,int end,int treeindex){
if(start==end){
 node *ans=new node();
ans->first=arr[start]->first;
ans->second=arr[start]->second;
ans->index=start;
tree[treeindex]=ans;
return ans;
}
int mid=(start+end)/2;
node *ans1=buildtree(arr,tree,start,mid,2*treeindex);
node *ans2=buildtree(arr,tree,mid+1,end,2*treeindex+1);
 node *ans=new node();
if(ans1->first>ans2->first){
 ans->first=ans1->first;
ans->second=ans1->second;
ans->index=ans1->index;
}
else if(ans1->first<ans2->first){
 ans->first=ans2->first;
ans->second=ans2->second;
ans->index=ans2->index;

} else{
 if(ans1->second<ans2->second){
     ans->first=ans1->first;
ans->second=ans1->second;
ans->index=ans1->index;

}else if(ans1->second>ans2->second){
      ans->first=ans2->first;
ans->second=ans2->second;
ans->index=ans2->index;

}else{
  ans->first=ans1->first;
  ans->first=ans2->second;
if(ans1->index<ans2->index){
 ans->index=ans1->index;
}
else if(ans2->index<ans1->index){
ans->index=ans2->index;
}
}
}
 tree[treeindex]=ans;
return ans;
}
node* query(node**tree,int start,int end,int treeindex,int left,int right){
if(start>end||start>right||end<left){
 node *ans=new node();
 return ans;
}
if(start>=left&&end<=right){
	return tree[treeindex];
}
int mid=(start+end)/2;
node *ans1=query(tree,start,mid,2*treeindex,left,right);
node *ans2=query(tree,mid+1,end,2*treeindex+1,left,right);
node *ans=new node();
if(ans1->first>ans2->first){
 ans->first=ans1->first;
ans->second=ans1->second;
ans->index=ans1->index;
}
else if(ans1->first<ans2->first){
 ans->first=ans2->first;
ans->second=ans2->second;
ans->index=ans2->index;

} else{
 if(ans1->second<ans2->second){
     ans->first=ans1->first;
ans->second=ans1->second;
ans->index=ans1->index;

}else if(ans1->second>ans2->second){
      ans->first=ans2->first;
ans->second=ans2->second;
ans->index=ans2->index;

}else{
  ans->first=ans1->first;
  ans->first=ans2->second;
if(ans1->index<ans2->index){
 ans->index=ans1->index;
}
else if(ans2->index<ans1->index){
ans->index=ans2->index;
}
}
}
return ans;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
  int n;
cin>>n;
node** arr=new node*[n];
for(int i=0;i<n;i++){
arr[i]=new node();
cin>>arr[i]->first;
arr[i]->index=i;
}
for(int i=0;i<n;i++){

 cin>>arr[i]->second;
}
node**tree=new node*[4*n];
buildtree(arr,tree,0,n-1,1);
int q;
cin>>q;
int left,right;
for(int i=0;i<q;i++){
cin>>left>>right;
 cout<<query(tree,0,n-1,1,left-1,right-1)->index+1<<endl;
}
 return 0;

}