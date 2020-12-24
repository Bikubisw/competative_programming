#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxprofit=0;
    int curr=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]){
                 curr=arr[j]-arr[i];
            }
            if(curr>maxprofit){
                maxprofit=curr;
            }
            
        }
    }
    cout<<maxprofit<<endl;
}