#include<iostream>
#include<vector>
using namespace std;
void printSolution(vector<vector<int>>&board,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
bool isSafe(int row,int col,vector<vector<int>>&board,int n){
    // Check if we can place queen
    // current cell[row,col] pr Queen rakhenge
    int i = row;
    int j = col;
    // Check left row 
    while(j>=0){
        if(board[i][j] == 1){ // Queen found and hence can't place it here
            return false;
        }
        j--;
    }
    // Check upper left diagonal
    i = row;
    j = col;
    while(i>=0 && j>=0){
        if(board[i][j] == 1){ // Queen found and hence can't place it here
            return false;
        }
        i--;
        j--;
    }
    // Check bottom left diagonal
    i = row;
    j = col;
    while(i<n && j>=0){
        if(board[i][j] == 1){ // Queen found and hence can't place it here
            return false;
        }
        i++;
        j--;
    }
    
    // If we are at this line means kahin pr bhi queen nhi mili
    // The position is safe
    //Place Queen
    return true;

}
void solve(vector<vector<int>>&board,int col,int n){
    // Base Case -> When we have placed queens in all the columns then col will go to n
    if(col >= n){
        printSolution(board,n);
        return;
    }
    // Just Solve one case 
    // In every row, place the queen
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // Place the queen then
            board[row][col] = 1; // 1 means queen, 0 means no queen
            // Recursive call for col + 1
            solve(board,col+1,n);
            // Backtracking -> Create original state
            board[row][col] = 0; // Queen removed 
        }
    }
}
int main(){
    int n = 5;
    // Initially all are zeroes in the nxn chessboard
    vector<vector<int>>board(n,vector<int>(n,0)); 
    int col = 0;//0 -> empty cell //1 -> Queen at cell
    solve(board,col,n);
    return 0;
}   