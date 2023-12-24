#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*

!Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

? Input: s = “aab”
? Output: [ ["a","a","b"], ["aa","b"] ]	
*/

//!Bruteforce aproach
/*
*Time Complexity: O( (2^n) *k*(n/2) )

*Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for *inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

*Space Complexity: O(k * x)

*Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of *palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the *auxiliary space required is equal to the O(n).
*/
bool isPalindrome(string s,int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}
void helper(string s,int idx,vector<string> path,vector<vector<string>> & ans){
    if(idx==s.length()){
        ans.push_back(path);
          return;
    }
  
    for(int i=idx;i<s.length();i++){
        if(isPalindrome(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));
            helper(s,i+1,path,ans);
            path.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    helper(s,0,path,ans);
    return ans;
}   

int main(){

}