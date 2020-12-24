#include<bits/stdc++.h>
using namespace std;
#define N 9
bool issaferow(int arr[N][N],int row,int num){
    for(int i=0;i<N;i++){
        if(arr[row][i]==num){
            return false;
        }
    }
    return true;
}
bool issafecol(int arr[N][N], int col, int num) {
    for (int i=0;i<N;i++) {
        if (arr[i][col]==num) {
            return false;
        }
    }
    return true;

}
bool issafegrid(int arr[N][N], int row,int col,int num) {
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(arr[i+rowfactor][j+colfactor]==num){
            return false;
        }
    }
}
return true;

}
bool issafe(int arr[N][N], int row, int col, int num) {
    if(issaferow(arr,row,num)&&issafecol(arr,col,num)&&issafegrid(arr,row,col,num)){
        return true;
    }
    return false;
}
bool findemptylocation(int arr[N][N], int &row, int &col) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (arr[i][j]==0) {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool solve(int arr[N][N]) {
    int row;int col;
    if(!findemptylocation(arr,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(issafe(arr,row,col,i)){
            arr[row][col]=i;
            bool ans=solve(arr);
            if(ans){
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}
int main(){
    int arr[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    solve(arr);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}