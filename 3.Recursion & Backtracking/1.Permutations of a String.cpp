#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
? Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.
?Input: arr = [1, 2, 3]

?Output: 
*[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

*/

//! Backtracking approach

//?Time Complexity: O(N! X N)

//?Space Complexity: O(1)

void helper(vector<int> & nums,int idx,vector<vector<int>> & ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,0,ans);
        return ans;
    }

//! Recursive approach
//?Time Complexity:  N! x N
//?Space Complexity:  O(N)
void helper(vector<int> & nums,vector<int> &freq,vector<int> ds,vector<vector<int>> &ans){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            helper(nums,freq,ds,ans);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(),0);
    helper(nums,freq,ds,ans);
    return ans;
}

int main(){

}