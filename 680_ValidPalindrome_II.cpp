// 680. Valid Palindrome II
//
/*
 *  Given a non-empty string s, you may delete at most one character.
 *  Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:

    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
  bool validPalindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
      int j = s.length() - 1 - i;
      if (s[i] != s[j]) {
        return validPalindromeRange(s, i, j - 1) ||
          validPalindromeRange(s, i + 1, j);
      }
    }
    return true;
  }
private:
  bool validPalindromeRange(string& s, int start, int end) {
    while (start < end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};

