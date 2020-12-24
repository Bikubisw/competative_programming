#include<bits/stdc++.h>
using namespace std;
int  magichelper(int**arr,int si,int sj,int ei,int ej){
    if(si==ei&&sj==ej){
        return 1;
    }
    if(si>ei||sj>ej){
        return 0;
    }
    int option1=magichelper(arr,si+1,sj,ei,ej)-arr[si+1][sj];
    int option2=magichelper(arr,si,sj+1,ei,ej)-arr[si][sj+1];
   int ans=min(option1,option2);
   if(ans<=0){
       return 1;
   }else{
       return ans;
   }
}
int magic(int**arr,int m,int n){
    return magichelper(arr,0,0,m-1,n-1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int**arr=new int*[m];
        for(int i=0;i<m;i++){
            arr[i]=new int[n];
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        cout<<magic(arr,m,n)<<endl;
    }
    return 0;
}