#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

/*
*Problem Statement
!Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

?Input  :  candidates = [10,1,2,7,6,1,5], target = 8
?Output : [
? [1,1,6],
? [1,2,5],
? [1,7],
? [2,6]
? ]


*/

//? Optimal Way 

//!Time Complexity:O(2^n*k)
//?Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also 
//?add the ds to our ans when we reach the base case that will take “k”//average space for the ds.
//!Space Complexity:O(k*x)

//?Reason: if we have x combinations then space will be x*k where k is the average length of the combination.

 void helper(vector<int> &arr,int idx,int target,vector<int> &ds,vector<vector<int>>& ans){
        if(target==0){
             ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i > idx && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i] > target){
                break;
            }
            ds.push_back(arr[i]);
            helper(arr,i+1,target-arr[i],ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
       
        helper(candidates,0,target,ds,ans);
        return ans;
    }

int main(){

}