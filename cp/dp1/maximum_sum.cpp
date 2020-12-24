#include<bits/stdc++.h>
using namespace std;
#define inf numeric_limits<long long int>::max()
#define ll long long int
int arr[101][101];
ll kadnane(vector<ll> v){
    int n=v.size();
    ll curr_sum=0;
    ll maxsum=0;
    ll me=-inf;
    for(int i=0;i<n;i++){
        curr_sum+=v[i];
        if(curr_sum<0){
            curr_sum=0;
        }
        maxsum=max(curr_sum,maxsum);
        me=max(me,v[i]);
    }
    if(me<0){
        return me;
    }else{
    return maxsum;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ll maxsum=-inf;
    for(int i=0;i<n;i++){
        vector<ll> v(m,0);
        for(int l=i;l<n;l++){
            for(int j=0;j<m;j++){
                v[j]+=arr[j][l];
            }
            maxsum=max(kadnane(v),maxsum);

        }


    }
    cout<<maxsum<<endl;
    return 0;
}