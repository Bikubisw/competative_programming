#include<bits/stdc++.h>
using namespace std;
void mazhelp(int n,int maze[][20],int **output,int x,int y){
    if(x==n-1&&y==n-1){
        output[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<output[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    if(x>=n||x<0||y>=n||y<0||maze[x][y]==0||output[x][y]==1){
        return;
    }
        output[x][y]=1;
        mazhelp(n,maze,output,x,y+1);
        mazhelp(n, maze, output, x, y-1);
        mazhelp(n, maze, output, x+1, y);
        mazhelp(n, maze, output, x-1, y);
        output[x][y]=0;

}
void ratInAMaze(int maze[][20], int n) {
    int **output=new int*[n];
    for (int i=0;i<n;i++) {
        output[i]=new int[n];
        for (int j=0;j<n;j++) {
            output[i][j]=0;
        }

    }
    mazhelp(n,maze,output,0,0);

}
int main() {
    int n;
    cin>>n;
    int arr[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ratInAMaze(arr,n);
}