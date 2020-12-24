#include<bits/stdc++.h>
using namespace std;
int balance(int n){
    if(n==0||n==1){
        return 1;
    }
    int MOD = (int)(pow(10, 9)) + 7;
    int x=balance(n-1);
    int y=balance(n-2);
    long res1=(long)x*x;
    long res2=(long)x*y*2;
    int ans1=(int)(res1%MOD);
    int ans2=(int)(res2%MOD);
    int ans=(ans1+ans2)%MOD;
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<balance(n)<<endl;
    return 0;
}