// 1143. Longest Common Subsequence
/*
 * Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with
some characters(can be none) deleted without changing the relative order of the
remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).
A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    The input strings consist of lowercase English characters only.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  // Solution 1: Recursion + memorization
  // Top down approach
  // 如果最后的字符相同, 则递归LCS(n1 - 1, n2 - 1) + 1
  // 如果字符不同, 则递归max(LCS(n1 - 1, n2), LCS(n1, n2 - 1))
  int longestCommonSubsequence_recursion(string text1, string text2) {
    const int m = text1.size();
    const int n = text2.size();
    mem_ = vector<vector<int>>(m+1, vector<int>(n+1, -1));
    LCS(m, n, text1, text2);
    return mem_[m][n];
  }

  // Solution 2: DP  bottom up approach
  int longestCommonSubsequence_dp(string text1, string text2) {
    const int m = text1.size();
    const int n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (text1[i] == text2[j])
          dp[i+1][j+1] = dp[i][j] + 1;
        else
          dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
      }
    }
    return dp[m][n];
  }

private:
  vector<vector<int>> mem_;

  int LCS(int idx1, int idx2, string& text1, string& text2) {
    if (idx1 == 0 || idx2 == 0) return 0;  // 递归终止条件
    if (mem_[idx1][idx2] != -1) return mem_[idx1][idx2];  // 记忆化
    if (text1[idx1-1] == text2[idx2-1]) {
      mem_[idx1][idx2] = 1 + LCS(idx1-1, idx2-1, text1, text2);
      return mem_[idx1][idx2];
    } else {
      return mem_[idx1][idx2] = std::max(LCS(idx1 - 1, idx2, text1, text2),
          LCS(idx1, idx2-1, text1, text2));
    }
  }
};

int main() {
  string s1 = "abcd";
  string s2 = "bd";
  cout << Solution().longestCommonSubsequence_recursion(s1, s2) << endl;
  return 0;
}


