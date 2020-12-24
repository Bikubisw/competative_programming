#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n>>k>>x;
    int arr[100001];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int freq[2][1024]={0};
    for(int i=0;i<n;i++){
        freq[0][arr[i]]++;
        freq[1][arr[i]]++;
    }
    for(int i=0;i<k;i++){
        int curr=0;
        for(int j=0;j<1024;j++){
            if(freq[0][j]==0){
                continue;
            }
            if(curr%2==0){
                int ans=(freq[0][j]+1)/2;
                freq[1][x^j]+=ans;
                freq[1][j]-=ans;
            }else{
                int ans=(freq[0][j])/2;
                freq[1][x^j]+=ans;
                freq[1][j]-=ans;
            }
            curr+=freq[0][j];
        }
        for(int i=0;i<1024;i++){
            freq[0][i]=freq[1][i];
        }
    }
    int i;
    for( i=1023;i>=0;i--){
        if(freq[0][i]>0){
            break;
        }
    }
    cout<<i<<" ";
for(i=0;i<1024;i++){
    if(freq[0][i]>0){
        break;
    }
}
cout<<i<<endl;
    return 0;

    
}