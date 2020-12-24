#include<bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
    int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
 cin>>arr[i];
}

sort(arr.begin(),arr.end(),greater<int>());
for(int i=0;i<n-2;i++){
 if(arr[i+1]+arr[i+2]<=arr[i]){
 continue;
}

else{
 cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i]<<endl;
return 0;
}

}
cout<<-1<<endl;


}
