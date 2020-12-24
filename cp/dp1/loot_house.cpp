#include<bits/stdc++.h>
using namespace std;
int getmoney(int*arr,int n){
    // if(n<=0){
    //     return 0;
    // }
    // int option1 = getmoney(arr+2,n-2)+arr[0];
    // int option2=getmoney(arr+1,n-1);
    // return max(option1,option2);
    int *output=new int[n];
    output[0]=arr[0];
    output[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        output[i]=max(arr[i]+output[i-2],output[i-1]);
    }
    int ans=output[n-1];
    delete[] output;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getmoney(arr,n)<<endl;
    return 0;
}