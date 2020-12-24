#include <bits/stdc++.h>
using namespace std;
int minCounthelper(vector<int> a,int val,int index){
    if(index==a.size()){
        return 0;
    }
    if(val==0){
        return 1;
    }
    if(val<0){
        return 0;
    }
    int count1=minCounthelper(a,val-(a[index]*a[index]),index);
    int count2=minCounthelper(a,val,index+1);
    return 1+min(count1,count2);
}
int minCount(int n){
    vector<int> a;
    for(int i=1;i<=floor(sqrt(n));i++){
        a.push_back(i);
    }
    return minCounthelper(a,n,0);
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}
