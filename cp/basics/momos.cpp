#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prefix_sum=arr[0];
    for (int i=1;i<n;i++) {
        int temp=arr[i];
        arr[i]=arr[i]+prefix_sum;
        prefix_sum+=temp;
    }
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        int start=0;
        int end=n-1;
        if(k<arr[0]){
            cout<<0<<" "<<k<<endl;
            continue;
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==k){
                int ans=mid+1;
                cout<<ans<<" "<<0<<endl;
                break;
            }else if(arr[mid]<k){
                if(arr[mid+1]>k){
                    cout<<mid+1<<" "<<(k-arr[mid])<<endl;
                    break;
                }else{
                    start=mid+1;
                }
            }
            else{
                end=mid-1;
            }
        }
    }
    delete[] arr;
    return 0;
}