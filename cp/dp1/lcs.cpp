#include<bits/stdc++.h>
using namespace std;
int lcs(int *input,int n){
    int *output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>input[i]){
                continue;
            }
            int possibleans=output[j]+1;
            if(possibleans>output[i]){
                output[i]=possibleans;
            }

        }
    }
    int best=INT_MIN;
    for(int i=0;i<n;i++){
        if(output[i]>best){
            best=output[i];
        }
    }
    return best;
}
int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lcs(arr,n)<<endl;
    return 0;
}