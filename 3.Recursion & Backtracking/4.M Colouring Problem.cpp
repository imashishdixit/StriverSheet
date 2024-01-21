#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
?Problem Statement - Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

*N = 4
*M = 3
*E = 5
*Edges[] = {
*  (0, 1),
*  (1, 2),
*  (2, 3),
*  (3, 0),
*  (0, 2)
*}

*Output: 1

*Explanation: It is possible to colour the given graph using 3 colours.

*/

//! Time Complexity: O( N^M) (n raised to m)

//? Space Complexity: O(N)

bool isSafe(int node,bool graph[101][101],int * color,int code,int m,int n){
    for(int k=0;k<=n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==code){
            return false;
        }
    }
    return true;
}
bool solve(int node, bool graph[101][101],int * color,int m,int n){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node,graph,color,i,m,n)){
            color[node]=i;
            if(solve(node+1,graph,color,m,n)){
                return true;
            }
            else{
                color[node]=0;
            }
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n]={0};
    return solve(0,graph,color,m,n);
}

int main(){

}