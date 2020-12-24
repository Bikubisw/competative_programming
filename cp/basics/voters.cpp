#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int *arr=new int[n1+n2+n3];
    for(int i=0;i<(n1+n2+n3);i++){
        cin>>arr[i];
    }
    map<int,int> mp;
    for(int i=0;i<(n1+n2+n3);i++){
        mp[arr[i]]++;
    }
    set<int> s;
    for(int i=0;i<(n1+n2+n3);i++){
        if(mp[arr[i]]>=2){
            s.insert(arr[i]);
        }
    }
    cout<<s.size()<<endl;
    set<int>:: iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}