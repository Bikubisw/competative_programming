#include <iostream>
using namespace std;
typedef long long ll;

ll merge(ll*arr,int start,int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int size=end-start+1;
    ll output[size];
    int k=0;
    ll count=0;
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            output[k++]=arr[i++];
        }else{
            output[k++]=arr[j++];
            count+=(mid+1)-i;
        }
    }
    while(i<=mid){
        output[k++]=arr[i++];
    }while(j<=end){
        output[k++]=arr[j++];
    }
    for(int i=start,m=0;i<=end;i++,m++){
        arr[i]=output[m];
    }
    //delete[] output;
    return count;
}
ll getInversionshelper (ll* arr,int start,int end){
    ll count=0;
    if(end>start){
    int mid=(start+end)/2;
    ll leftcount = getInversionshelper(arr,start,mid);
    ll rightcount = getInversionshelper(arr,mid+1,end);
    ll count=merge(arr,start,end);
    return leftcount+rightcount+count;
    }
    return count;
    }
ll getInversions(ll *arr, int n)
{
    return getInversionshelper(arr,0,n-1);
}

    int main()
{
    int n;
    cin >> n;

    ll* arr = new ll[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n)<<endl;

    delete arr;
}