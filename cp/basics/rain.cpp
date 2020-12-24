#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("rainin.txt", "r", stdin);
    freopen("rainout.txt", "w", stdout);
    int n,total;
    cin>>n>>total;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int l=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>=total){
            break;
        }
        l++;
    }
    cout<<l;
    delete [] arr;
    
    return 0;
}