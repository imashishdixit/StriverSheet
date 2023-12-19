#include<bits/stdc++.h>
using namespace std;
/
/*
?Set Matrix Zero
! Given an array print all the sum of the subset generated from it, in the increasing order.

!Input: N = 3, arr[] = {5,2,1}

!Output: 0,1,2,3,5,6,7,8
*/

//! Bruteforce approach
//? Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it.
//? So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
//! Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
void helper(vector<int> num,int n,int sum,vector<int> &res){
	if(n==0){
		res.push_back(sum);
		return;
	}
	helper(num,n-1,sum,res);
	helper(num,n-1,sum+num[n-1],res);
	return;
}

vector<int> subsetSum(vector<int> &num){
		int n=num.size();
		vector<int> res;
		helper(num,n,0,res);
		sort(res.begin(),res.end());
		return res;

}
int main(){

}