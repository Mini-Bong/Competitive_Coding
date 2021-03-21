#include <bits/stdc++.h>
int n;
using namespace std;
void printBoard(vector<vector<int>> board)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isSafe(vector<vector<int>> board, int row, int col){
    int i, j;
    for(i=0; i<col; i++){
        if(board[row][i]==1){
            return false;
        }
    }
    for(i = row, j = col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(i = row, j = col; j>=0, i<n; i++, j--)
    {
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
bool NqueenSolver(vector<vector<int>> &board, int col)
{
    if(col>=n){
        return true;
    }
    for(int i=0; i<n; i++)
    {
        if(isSafe(board, i, col)){
            board[i][col] = 1;
            if(NqueenSolver(board, col+1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
void solveNqueen(int n)
{
    vector<vector<int>> board(n, vector<int> (n, 0));
    if(NqueenSolver(board, 0))
    {
        printBoard(board);
    }
    else{
        cout<<"Solution does not exists";
    }
}
int main()
{
    cout<<"Enter chess board size: ";
    cin>>n;
    solveNqueen(n);
    return 0;
}
