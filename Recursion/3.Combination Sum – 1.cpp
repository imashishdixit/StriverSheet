#include<bits/stdc++.h>
using namespace std;
/*
!Problem Statement: 

*Given an array of distinct integers and a target, you have to return the list of all unique 
*combinations where the chosen numbers sum to target. You may return the combinations in any order.

*The same number may be chosen from the given array an unlimited number of times. 
*Two combinations are unique if the frequency of at least one of the chosen numbers is different.

*It is guaranteed that the number of unique combinations that sum up to target is less than 150 
*combinations for the given input.


?Input: array = [2,3,6,7], target = 7

?Output: [[2,2,3],[7]]

*/

//!Time Complexity: O(2^t * k) where t is the target, k is the average length

//*Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
//*Why not (2^n) but (2^t) (where n is the size of an array)?

//*Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

//*Space Complexity: O(k*x), k is the average length and x is the no. of combinations
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element 
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(ind + 1, target, arr, ans, ds);
}
vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}


int main(){
    vector < int > v {2,3,6,7};
    int target = 7;

    vector < vector < int >> ans = combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
        cout << ans[i][j] << " ";
        cout << endl;
    }
}