#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("encyin.txt", "r", stdin);
    freopen("encyout.txt", "w", stdout);
    int a,b;
    cin>>a>>b;
    int *arr=new int[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
   
    for(int i=0;i<b;i++){
        int page;
        cin>>page;
        cout<<arr[page-1]<<endl;
    }
    return 0;
}