#include<bits/stdc++.h>
using namespace std;
bool ispossible(int n,int row,int col,int **output){
    for(int i=row-1;i>=0;i--){
        if(output[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(output[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(output[i][j]==1){
            return false;
        }
    }
    return true;

}
void queenhelper(int n, int row, int **output) {
    if (row==n) {
    // we have reached the solution
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<output[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
for(int j=0;j<n;j++){
    if(ispossible(n,row,j,output)){
        output[row][j]=1;
        queenhelper(n,row+1,output);
        output[row][j]=0;
    }
}
return;
}
void queen(int n) {
    int **output=new int*[n];
    for(int i=0;i<n;i++){
        output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=0;
        }

    }
    queenhelper(n, 0, output);
}
int main(){
    int n;
    cin>>n;
    queen(n);
    return 0;
}