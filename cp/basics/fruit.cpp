#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("taktakin.txt","r",stdin);
    freopen("taktakout.txt", "w", stdout);
    int n;
    cin>>n;
    int i=0;
    while (n%11!=1){
        n*=2;
        i++;
    }
    cout<<i<<" "<<n<<endl;
}