#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("listin.txt", "r", stdin);
    freopen("listout.txt", "w", stdout);
    int arr[10001]={0};
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b]++;
    }
    int max=arr[0];
    for(int i=0;i<1001;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=0;i<1001;i++){
        if(arr[i]==max){
            cout<<i<<endl;
        }
    }
}