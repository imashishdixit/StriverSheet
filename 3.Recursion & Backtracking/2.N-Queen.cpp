#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
? Problem Statement - The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

!Input: n = 4

!Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

!Explanation: There exist two distinct solutions to the 4-queens puzzle as shown below
*/

/*
!!Solution 1 (Using Backtracking)
?Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O

?(N! * N) nearly.

?Space Complexity: O(N^2)
*/
bool isSafe(vector<string> & board,int x,int y){
    int n=board.size();
    int row=x;
    int col = y;
    
    while(x>=0){
        if(board[x][y]=='Q') return false;
        x--;
    }
    x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]=='Q') return false;
        x--;
        y--;
    }
    x=row;
    y=col;
    while(x>=0 && y<n){
        if(board[x][y]=='Q') return false;
        x--;
        y++;
    }
    return true;
}
void helper(vector<string>& board,int idx,int n,vector<vector<string>>&ans){
    if(idx==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,idx,i)){
                board[idx][i]='Q';
                helper(board,idx+1,n,ans);
            board[idx][i]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    helper(board,0,n,ans);
    return ans;
}


//! Solution - 2 optimization is in the isSafe function


int main(){

}