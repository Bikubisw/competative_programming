#include<bits/stdc++.h>
using namespace std;
int pro(vector<int>& arr){
    int max_ending_here=1;
    int min_ending_here=1;
    int max_so_far=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            max_ending_here=max_ending_here*arr[i];
            min_ending_here=min(min_ending_here*arr[i],1);
        }
        else if(arr[i]==0){
            max_ending_here=1;
            min_ending_here=1;
        }
        else{
            int temp=max_ending_here;
            max_ending_here=max(min_ending_here*arr[i],1);
            min_ending_here=temp*arr[i];
        }
       max_so_far=max(max_so_far,max_ending_here);
    }
    return max_so_far;
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
    cout<<pro(arr)<<endl;
    return 0;
}