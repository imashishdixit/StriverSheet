#include<bit>
#include<vector.h>
#include<bitstdc++.h>

using namespace std;

/*
?Set Matrix Zero
! Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set 
! its entire column and row to 0 and then return the matrix.
*/

//! Bruteforce approach
//? Time Complexity O((m*n)*(m+n))+O(m*n) Space Complexity O(1)
void markRow(vector<vector<int>>& matrix,int i){
    int n=matrix[0].size()̦;
    for(int j=0;j<n;j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
    return;
}
void markCol(vector<vector<int>>& matrix,int j){
     int m=matrix.size()̦;
    for(int i=0;i<m;i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
    return;
}
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    markRow(matrix,i); 
                    markCol(matrix,j); 
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
}

//! Better Approach
//? Time Complexity O(2*m*n) Space Complexity O(m) + O(n)
void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
}

//! Optimal Approach
//? Time Complexity O(m*n) Space Complexity O(1)
void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     
        int n= matrix[0].size();
        int col0 = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0) //? except first col
                        matrix[0][j]=0;
                    else  //! for the first col
                        col0 = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){  //? if the first element 
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        return;

}

