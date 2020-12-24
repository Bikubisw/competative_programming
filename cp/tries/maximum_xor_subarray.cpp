#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class TrieNode{
  public:
  TrieNode* left;
 TrieNode* right;
}; 
void inserttree(TrieNode* head,int val){
 TrieNode* curr=head;
for(int i=31;i>=0;i--){
 int b=(val>>i)&1;
if(b==0){
 if(!curr->left){
curr->left=new TrieNode();
}
curr=curr->left;
}else{
 if(!curr->right){
curr->right=new TrieNode();
}
curr=curr->right;                 	
}
}
}
ll query(TrieNode* head,ll val,int n){
   TrieNode* curr=head;
  ll maxxor=0;
ll currxor=0;
for(int i=31;i>=0;i--){
 int b=(val>>i)&1;
if(b==0){
 if(curr->right){
   currxor+=pow(2,i);
curr=curr->right;

}else{
 curr=curr->left;
}
}else{
 if(curr->left){
   currxor+=pow(2,i);
curr=curr->left;

}else{
 curr=curr->right;
}
}
}
maxxor=max(currxor,maxxor);
return maxxor;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}

ll mxor=0;
ll ans=0;
TrieNode *head=new TrieNode();
inserttree(head,mxor);
for(int i=0;i<n;i++){
 mxor^=arr[i];
ans=max(ans,query(head,mxor,n));
inserttree(head,mxor);
}
cout<<ans<<endl;

 return 0;
}