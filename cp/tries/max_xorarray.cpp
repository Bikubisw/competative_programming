#include<bits/stdc++.h>
using namespace std;
class Trienode{
  public:
	Trienode*left;
	Trienode*right;
};
void insert(int val,Trienode*head){
Trienode* curr=head;
for(int i=31;i>=0;i--){
 int b=(val>>i)&1;
if(b==0){
 if(!curr->left){
   curr->left=new Trienode();
}
curr=curr->left;
}else{
if(!curr->right){
     curr->right=new Trienode();
}
curr=curr->right;
}
}
}
int findmaxxor(Trienode*head,vector<int>&arr,int n){
 int maxxor=INT_MIN;
for(int i=0;i<n;i++){
 Trienode*curr=head;
int currxor=0;
for(int j=31;j>=0;j--){
 int b=(arr[i]>>j)&1;
if(b==0){
 if(curr->right){
 curr=curr->right;
currxor+=pow(2,j);
}else{
 curr=curr->left;
}
}else{
 if(curr->left){
 curr=curr->left;
currxor+=pow(2,j);
}else{
 curr=curr->right;
}
}
}
maxxor=max(currxor,maxxor);
}
return maxxor;
}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}
Trienode* head=new Trienode();
for(int i=0;i<n;i++){
 insert(arr[i],head);
}
cout<<findmaxxor(head,arr,n)<<endl;

return 0;
}