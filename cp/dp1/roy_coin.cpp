#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int start[n+1]={0};
    int end[n+1]={0};
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int first,second;
        cin>>first>>second;
        start[first]++;
        end[second]++;
    }
    int arr[n+1]={0};
    arr[1]=start[1];
    for(int i=2;i<=n;i++){
        arr[i]=start[i]-end[i-1]+arr[i-1];
    }
    int arr2[n+1]={0};
    for(int i=1;i<=n;i++){
        arr2[arr[i]]++;
    }
    int arr3[n+1]={0};
    arr3[n]=arr2[n];
    for(int i=n-1;i>=1;i--){
        arr3[i]=arr2[i]+arr3[i+1];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int first;
        cin>>first;
        cout<<arr3[first]<<endl;
        cout.flush();
    }
    return 0;
}