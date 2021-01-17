// 1641. Count Sorted Vowel Strings
/*
 * Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

Example 3:

Input: n = 33
Output: 66045

Constraints:
    1 <= n <= 50
*/
// Dynamic Programming
class Solution {
public:
  int countVowelStrings(int n) {
    vector<vector<int>> memo(n + 1, vector<int>(6, 0));
    return countVowelStringUtil(n, 5, memo);
  }
private:
  int countVowelStringUtil(int n, int vowels, vector<vector<int>>& memo) {
    if (n == 1)
      return vowels;
    if (vowels == 1)
      return 1;
    if (memo[n][vowels] != 0)
      return memo[n][vowels];
    int res = countVowelStringUtil(n - 1, vowels, memo) +
              countVowelStringUtil(n, vowels - 1, memo);
    return memo[n][vowels] = res;
  }
};


