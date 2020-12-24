#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;
class Interval{
    public:
    int st;
    int se;
};
bool compare(Interval I1,Interval I2){
    return I1.st<I2.st;
}
int main(){
    // vector<int> arr(5);
    // vector<int>::iterator it;
    // for(it=arr.begin();it!=arr.end();it++){
    //     cout<<*it<<endl;
    // }
    // string s="dgdbsjbdjas";
    // cout<<s.substr(1,4)<<endl;
    // pair<int,char> p(1,'e');
    // pair<int,char> p2;
    // p2=make_pair(5,'k');
    // cout<<p.first<<" "<<p.second<<endl;
    // cout << p2.first << " " << p2.second << endl;
    // set<int> s;
     int arr[]={452,123,56,89,89,75,63,25,36};
    // for(int i=0;i<8;i++){
    //     s.insert(arr[i]);
    // }
    // set<int>:: iterator it;
    // for(it=s.begin();it!=s.end();it++){
    //     cout<<*it<<" ";
    // }
    // if(s.find(6)==s.end()){
    //     cout<<"Not found"<<endl;
    // }else{
    //     cout<<"found"<<endl;
    // }
    //Interval arr[]={{5,8},{1,6},{2,4},{0,5}};
    //sort(arr,arr+4,compare);
    // for(int i=0;i<4;i++){
    //     cout<<arr[i].st<<":"<<arr[i].se<<endl;
    // }
    sort(arr,arr+8);
    //cout<<binary_search(arr,arr+8,5);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<lower_bound(arr,arr+8,89)-arr<<endl;
    cout<<upper_bound(arr,arr+8,89)-arr<<endl;
    //cout<<arr+1<<endl;
    
    return 0;
}