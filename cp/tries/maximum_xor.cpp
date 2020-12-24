#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
  TrieNode* left;
  TrieNode* right;
};
void inserttree(int val,TrieNode* head){
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
int maxelement(TrieNode* head,int*arr,int n){
   int maxxor=INT_MIN;
for(int i=0;i<n;i++){
int currxor=0;
 TrieNode* curr=head;
for(int j=31;j>=0;j--){
 int b=(arr[i]>>j)&1;
if(b==0){
 if(curr->right){
currxor+=pow(2,j);
curr=curr->right;
}else{
  curr=curr->left;
}
}else{
 if(curr->left){
currxor+=pow(2,j);
curr=curr->left;
}else{
  curr=curr->right;
}


}
}
maxxor=max(currxor,maxxor);
}
return maxxor;
}
int main()
{
int n;
cin>>n;
int*arr=new int[n];
for(int i=0;i<n;i++){
 cin>>arr[i];
}
TrieNode* head=new TrieNode();
for(int i=0;i<n;i++){
 inserttree(arr[i],head);
}
cout<<maxelement(head,arr,n)<<endl;

 return 0;
}