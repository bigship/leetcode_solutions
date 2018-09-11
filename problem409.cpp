// 409. Longest Palindrome

/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

*/

// count frequency of every character in the string
// if freq is even, add freq to total result
// if freq is odd, add freq - 1 to total result (may have one left)
// if freq is odd, means we can have one single character left which may add to the middle to make a valid palindrome string
// CAUTION: if we have multiply left characters, we can only add one of them to the middle

class Solution {
public:
  int longestPalindrome(string s) {
    vector<int> freqs(128, 0);
    int ans = 0;
    for (const char c : s) {
      ++freqs[c];
    }

    int odd = 0;
    for (const int freq : freqs) {
      ans += (freq % 2 == 0 ? freq : freq - 1);
      if (freq & 1) odd = 1;   // only count once
    }

    return ans + odd;
  }
}