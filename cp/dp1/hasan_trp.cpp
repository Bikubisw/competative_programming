#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
#define inf numeric_limits<long long int>::max()
typedef long long ll;
#define pdd pair<double,double> 

pdd d[3002];
double dp[3002];
double F[3002];
double distance(pdd x, pdd y)
{
    double ans = sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
    return  ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        d[i]=make_pair(x,y);
        F[i]=z;
    }
    dp[0]=F[0];
    for(int i=1;i<n;i++){
        dp[i]=-inf;
        for(int j=0;j<i;j++){
            double z=distance(d[i],d[j]);
            cout<<dp[i]<<" "<<dp[j]-z<<endl;
            dp[i]=max(dp[i],dp[j]-z);
        }
        dp[i]+=F[i];
    }
    cout<<fixed;
    cout<<setprecision(6)<<dp[n-1]<<endl;


}