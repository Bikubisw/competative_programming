#include<bits/stdc++.h>
using namespace std;
class TrieNode{
  public:
       int cnt;
	TrieNode* left;
       TrieNode* right;
     TrieNode(){
 cnt=0;
left=NULL;
right=NULL;
}
};
void buildtree(TrieNode* head,int val){
TrieNode* curr=head;
for(int i=31;i>=0;i--){
 int b=(val>>i)&1;
if(b==0){
if(!curr->left){
 curr->left=new TrieNode();
curr->left->count=1;
}else{
(curr->left->count)++;
}
curr=curr->left;
}else{
if(!curr->right){
 curr->right=new TrieNode();
curr->right->count=1;
}else{
(curr->right->count)++;
}
curr=curr->right;
}
}


}
int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t;
cin>>t;
while(t--){
 int n,k;
cin>>n>>k;
int*arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}
int mxor=0;
TrieNode* head=new TrieNode();
buildtree(head,mxor);
for(int i=0;i<n;i++){

}

}
delete[] arr;
return 0;
}