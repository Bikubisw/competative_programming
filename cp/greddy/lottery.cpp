#include<bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
   int s,d;
cin>>s>>d;
vector<int> dp(d);
int currsum=s-1;
int sum=0;
for(int i=d-1;i>=1;i--){
 if(currsum>9){
 dp[i]=9;
currsum-=9;
sum+=9;

}
else if(currsum==0){
 dp[i]=0;
}
else{
 dp[i]=currsum;
sum+=currsum;
currsum=0;
}
}
dp[0]=s-sum;
for(int i=0;i<d;i++){
 cout<<dp[i];
}
cout<<endl;
 return 0;

}