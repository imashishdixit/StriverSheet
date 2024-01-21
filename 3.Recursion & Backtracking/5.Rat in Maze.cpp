#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
? Problem Statement - 
!Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

!Note: In a path, no cell can be visited more than one time.

!Print the answer in lexicographical(sorted) order

*/

//*Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

//*Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).




 bool isSafe(int dx,int dy,int n){
    return dx>=0 && dx<n && dy>=0 && dy<n;
}
void solve(vector<vector<int>> &m, int n,int x,int y,vector<string> &ans,string path,vector<vector<bool>>& visited){
    if(x==(n-1) && y==(n-1)){
        ans.push_back(path);
        return;
    }
    vector<int> xx=  {1,0,0,-1};
    vector<int> yy = {0,-1,1,0};
    
    string dir = "DLRU";
    for(int i=0;i<4;i++){
        int dx = x+xx[i];
        int dy = y+yy[i];
        
        if(isSafe(dx,dy,n) && !visited[dx][dy] && m[dx][dy]==1){
            visited[x][y]=1;
            solve(m,n,dx,dy,ans,path+dir[i],visited);
            visited[x][y]=0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    if(m[0][0]==1 ) solve(m,n,0,0,ans,"",visited);
    return ans;
}
int main(){

}