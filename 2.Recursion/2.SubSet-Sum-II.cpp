 #include<iostream>
 #include<set>
using namespace std;


/*
?Subset – II | Print all the Unique Subsets
! Problem Statement: : Given an array of integers that may contain duplicates the task is to return all possible subsets. 
! Return only unique subsets and they can be in any order.

? Input: array[] = [1,2,2]

? Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
*/

//! Bruteforce approach
//? Time Complexity - O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  
//? to insert every combination of average length k in a set of size x. After this, we have to convert the set of 
//? combinations back into a list of list /vector of vectors which takes more time.
//! Space Complexity - O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another 
//! O(2^n *k) is also used.
void helper(vector<int> nums,int n,vector<int> temp,set<vector<int>> & des){
    if(n==0){
        sort(temp.begin(),temp.end());
        des.insert(temp);
        return;
    }
    temp.push_back(nums[n-1]);
    helper(nums,n-1,temp,des);
    temp.pop_back();
    helper(nums,n-1,temp,des);
    return;
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    set<vector<int>> des;
    helper(nums,nums.size(),temp,des);
    for(auto it = des.begin();it!=des.end();it++){
        res.push_back(*it);
    }
    return res;
}

//! Optimal approach
/*
!Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure 
! if the average length of every subset is k. Overall O(k * 2^n).

! Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  
! if n is the depth of the recursion tree.
*/

 void helper(vector<int> &nums,int idx,vector<int> ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            helper(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(nums,0,ds,ans);
        return ans;
    }

int main(){

}