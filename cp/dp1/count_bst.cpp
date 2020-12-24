#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MOD 1000000007;
typedef long long ll;
using namespace std;
int countBST(int n){
    int*arr=new int[n+1]();
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            ll ans=((ll)arr[i-j])*arr[j-1];
            ans=ans%MOD;
            arr[i]=(arr[i]+ans)%MOD;
        }
    }
    return arr[n];

} 
int main()
{
    int n;
    cin >> n;
    cout << countBST(n);
    return 0;
}
