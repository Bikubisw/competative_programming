#include<bits/stdc++.h>
using namespace std;



int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
int *arr=new int[n];
 for(int i=0;i<n;i++){
 cin>>arr[i];
}
sort(arr,arr+n);
int minimum=INT_MAX;
for(int i=1;i<n;i++){
 if(arr[i]-arr[i-1]<minimum){
minimum=arr[i]-arr[i-1];
}

}
cout<<minimum<<endl;



 return 0;

}