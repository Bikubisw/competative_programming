#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int num=n;
int count=0;
while(num!=0){
   num=num/10;
    count++;
}
cout<<count<<endl;

return 0;

}
