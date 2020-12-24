#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
double value1=(double)a.first/a.second;
double value2=(double)b.first/b.second;
return value1>value2;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
 int n,W;
cin>>n>>W;
vector<pair<int,int>>arr(n);
for(int i=0;i<n;i++){
 cin>>arr[i].first;
cin>>arr[i].second;
}
sort(arr.begin(),arr.end(),compare);
    int currw=0;
double fvalue=0;
for(int i=0;i<n;i++){
 if(currw+arr[i].second<=W){
 currw+=arr[i].second;
fvalue+=arr[i].first;
} else{
    int remainwei=W-currw;
   fvalue+=((double)remainwei/arr[i].second)*arr[i].first;
	break;
}

}
cout<<fvalue<<endl;

 return 0;

}