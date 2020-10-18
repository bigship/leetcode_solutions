// 1119. Remove Vowels from a String
/*
 * Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:

Input: "aeiou"
Output: ""

Note:

    S consists of lowercase English letters only.
    1 <= S.length <= 1000
*/

class Solution {
public:
  string removeVowels(string S) {
    int write = 0, read = 0;
    const int n = S.length();
    while (write < n && read < n) {
      if (S[read] == 'a' || S[read] == 'e' ||
          S[read] == 'i' || S[read] == 'o' ||
          S[read] == 'u') {
        read++;
      } else {
        S[write] = S[read];
        write++;
        read++;
      }
    }
    return S.substr(0, write);
  }
};


