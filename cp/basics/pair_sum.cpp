#include <bits/stdc++.h>
using namespace std;
void pairSum(int*arr,int n){
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
    int complement=-1*arr[i];
    if(mp.find(complement)!=mp.end()){
        int num=mp[complement];
        while(num--){
            cout<<min(arr[i],complement)<<" "<<max(arr[i],complement)<<endl;
        }
    }
    mp[arr[i]]++;
}

}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    pairSum(arr, n);

    delete[] arr;

    return 0;
}