#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            sum+=arr[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}