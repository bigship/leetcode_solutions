// 459. Repeated Substring Pattern

/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:

Input: "aba"
Output: False

Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

*/

class Solution {
public:
  bool repeatedSubstringPattern(string str) {
    int len = str.size();
    if (len <= 1) return false;

    bool ans = true;
    for (int i = 1; i <= len / 2; i++) {
      if (len % i != 0) continue;
      string sub = str.substr(0, i);
      ans = true;
      for (int j = 0; j < len; j += i) {
        if (sub != str.substr(j, i)) {
          ans = false;
          break;
        }
      }
      if (ans) 
        return true;
    }

    return ans;
  }
};


