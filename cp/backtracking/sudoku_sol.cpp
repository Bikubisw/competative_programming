#include <bits/stdc++.h>
using namespace std;
bool issaferow(int arr[9][9], int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool issafecol(int arr[9][9], int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool issafegrid(int arr[9][9], int row, int col, int num)
{
    int rowfactor = row - (row % 3);
    int colfactor = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i + rowfactor][j + colfactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool issafe(int arr[9][9], int row, int col, int num)
{
    if (issaferow(arr, row, num) && issafecol(arr, col, num) && issafegrid(arr, row, col, num))
    {
        return true;
    }
    return false;
}
bool findempty(int board[9][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool sudokuSolver(int board[][9]){
    int row,col;
    if(!findempty(board,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(issafe(board,row,col,i)){
            board[row][col]=i;
            bool ans = sudokuSolver(board);
            if(ans){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 9;
    int board[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (sudokuSolver(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
