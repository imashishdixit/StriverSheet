#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
!Problem Statement
!Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

*         1. All the rows should be filled with numbers(1 – 9) exactly once.

*        2. All the columns should be filled with numbers(1 – 9) exactly once.

*         3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.

* Note: Character ‘.’ indicates empty cell.
*/
bool isValid(vector<vector<char>> & board,int row,int col,char ch){
    for(int i=0;i<9;i++){
        if(board[row][i]==ch){
            return false;
        }
        if(board[i][col]==ch){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> & board){
    int row=board.size();
    int col = board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(isValid(board,i,j,ch)){
                        board[i][j]=ch;
                        if(solve(board)){
                            return true;
                        }
                        else {
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            } 
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    bool res = solve(board);
    return;
}
int main(){

}