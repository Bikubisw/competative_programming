#include<bits/stdc++.h>
using namespace std;
vector<int> remove_duplicate(vector<int> arr){
    // set<int> s;
    vector<int> output;;
    // for(int i=0;i<arr.size();i++){
    //     if(s.find(arr[i])==s.end()){
    //         s.insert(arr[i]);
    //         output.push_back(arr[i]);
    //     }
    // }
    // return output;
    sort(arr.begin(),arr.end());
    output.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]){
            continue;
        }
        output.push_back(arr[i]);

    }
    return output;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> output;
    output=remove_duplicate(arr);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}