#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int*arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long *prod=new long[n];
        long lprod=1;
        for(int i=0;i<n;i++){
            prod[i]=lprod;
            lprod=lprod*arr[i];
        }
        long rprod=1;
        for(int i=n-1;i>=0;i--){
            prod[i]=rprod*prod[i];
            rprod=rprod*arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<prod[i]<<" ";
    }
    cout<<endl;
}
return 0;
}