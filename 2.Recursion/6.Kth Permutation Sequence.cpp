#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
/*
! Problem Statement : Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

? Example 1:

? Input: N = 3, K = 3
 
 ? Output: “213”
*/

//! Bruteforce approach
/*
*
Time complexity: O(N! * N) +O(N! Log N!)

*Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure

*Space complexity: O(N) 

*Reason: Result stored in a vector, we are auxiliary space taken by recursion
*/
class Solution {
  public:
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    return res[k-1];
  }
};

// int main() {
//   int n = 3, k = 3;
//   Solution obj;
//   string ans = obj.getPermutation(n, k);
//   cout << "The Kth permutation sequence is " << ans << endl;

//   return 0;
// }


//! Optimal Approach
/*
?Time Complexity: O(N) * O(N) = O(N^2)

?Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space ??by removing the element already placed in the previous step. This takes another O(N) time.

?Space Complexity: O(N) 

?Reason: We are storing  the numbers in a data structure(here vector)
*/

string getPermutation(int n, int k) {
    int fact = 1;
    vector < int > numbers;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
            break;
        }

        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main(){

}