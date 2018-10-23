// 266. Palindrome Permutation

/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false

Example 2:

Input: "aab"
Output: true

Example 3:

Input: "carerac"
Output: true
*/

class Solution {
public:
  bool canPermutePalindrome(string s) {
    vector<int> hash(128, 0);
    for (auto& ch : s) {
      if (hash[ch] == 0) {
        hash[ch] = 1;
      } else {
        hash[ch] += 1;
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < hash.size(); i++) {
      if (hash[i] != 0) cnt += 1;
    }
    if (cnt == 1) return true;
    
    int cntOfOdd = 0;
    for (int i = 0; i < hash.size(); i++) {
      if (hash[i] % 2 == 1) cntOfOdd += 1;
    }
    if (cntOfOdd > 1) return false;
    
    return true;
  }
};
