#include<bits/stdc++.h>
using namespace std;
int coinchange(int n,int* arr,int val,int ** output){
    if(n==0){
        return 0;
    }
    if(val==0){
        return 1;
    }
    if(val<0){
        return 0;
    }
    if (output[n][val] > -1)
    {
        return output[n][val];
    }
    int first=coinchange(n,arr,val-arr[0],output);
    int second=coinchange(n-1,arr+1,val,output);
    output[n][val] = first + second;
    return first+second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val;
    cin>>val;
    int** output=new int* [n+1];
    for(int i=0;i<=n;i++){
        output[i]=new int[val+1];
        for(int j=0;j<=val;j++){
            output[i][j] = -1;
        }
    }
    cout << coinchange(n, arr, val, output) << endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=val;j++){
            cout << output[i][j];
        }
        cout<<endl;
    }
    return 0;
 }