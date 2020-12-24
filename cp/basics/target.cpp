#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,tsum;
    cin>>n;
    cin>>tsum;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int si=0;
    int currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum==tsum){
            cout<<"true"<<endl;
            for(int j=si;j<=i;j++){
                cout<<arr[j]<<" ";
            }
            return 0;
        }
        else if (currsum>tsum)
        {
            currsum=arr[i];
            if(currsum==tsum){
                cout << "true" << endl;
                cout<<arr[i]<<endl;
                return 0;
            }
            si=i;
        }
    }
    cout<<"false"<<endl;
}