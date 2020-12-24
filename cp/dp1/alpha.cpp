#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    int n;
    long long int arr[5001];
    while(1){
        string s;
        cin>>s;
        if(s=="0"){
            break;
        }
        for(int i=0;i<5000;i++){
            arr[i]=0;
        }
        int n=s.length();
        arr[0]=1;
        for(int i=1;i<n;i++){
            int x=((s[i-1]-'0')*10)+(s[i]-'0');
            if(s[i]!='0'){
                arr[i]=arr[i-1];
            }
            if(x>=10&&x<=26&&i>1){
                arr[i]+=arr[i-2];
            }
            else if(x>=10&&x<=26){
                arr[i]++;
            }
            arr[i]=arr[i]%MOD;
        }
        cout<<arr[n-1]<<endl;
    }
    return 0;
}