#include<bits/stdc++.h>
using namespace std;
class weight{

 public:
	int start;
	int end;
	int profit;
	weight(int start,int end,int profit){
	this->start=start;
	this->end=end;
	this->profit=profit;
}

};
bool compare(weight a,weight b){
    return a.end<b.end;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
  int n;
cin>>n;
int start,end,profit;
vector<weight> input;
for(int i=0;i<n;i++){
 cin>>start>>end>>profit;
   input.push_back(weight(start,end,profit));
}
sort(input.begin(),input.end(),compare);
 vector<int> dp(n);
dp[0]=input[0].profit;
for(int i=1;i<n;i++){
int including=input[i].profit;
int lindex=-1;
 int start=0;
int end=i-1;
while(start<=end){
 int mid=start+(end-start)/2;
if(input[mid].end<=input[i].start){
if(input[mid+1].end<=input[i].start){
  start=mid+1;
}
else{
lindex=mid;
break;
}
}
else{
 end=mid-1;

}


}
if(lindex!=-1){
 including+= dp[lindex];
}
   dp[i]=max(dp[i-1],including);
}
cout<<dp[n-1]<<endl;
 return 0;

}