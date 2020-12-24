#include <bits/stdc++.h>
using namespace std;
int mincosthelper(int**arr,int si,int sj,int ei,int ej,int **output){
    if(si==ei&&sj==ej){
        return arr[ei][ej];
    }
    if(si>ei||sj>ej){
        return INT_MAX;
    }
    if(output[si][sj]>-1){
        return output[si][sj];
    }
    int option1 = mincosthelper(arr, si + 1, sj, ei, ej, output);
    int option2 = mincosthelper(arr, si, sj + 1, ei, ej, output);
    int option3 = mincosthelper(arr, si + 1, sj + 1, ei, ej, output);
    int ans= arr[si][sj]+min(option1,min(option2,option3));
    output[si][sj]=ans;
    return ans;
    
}
int mincost(int**arr,int m,int n,int **output){
    return mincosthelper(arr,0,0,m-1,n-1,output);
}
int main()
{
    int m,n;
    cin>>m>>n;
    int**arr=new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int **output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    cout<<mincost(arr,m,n,output)<<endl;
}