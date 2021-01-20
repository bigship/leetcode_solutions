// 516. Longest Palindromic Subsequence
/*
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"

Output:

4

One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:

"cbbd"

Output:

2

One possible longest palindromic subsequence is "bb".
Constraints:
    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/

// Solution 1: Recursion + Memorization  Top-down dynamic programming
// dp[i][j] = (s[i] == s[j]) ? (dp[i+1][j-2] + 2) : max(dp[i][j-1], dp[i+1][j])
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    for (int i = 0; i < dp.size(); i++) {
      dp[i][i] = 1;
    }
    return helper(s, 0, s.length() - 1, dp);
  }
private:
  int helper(string& s, int left, int right, vector<vector<int>>& dp) {
    if (left > right) {
      return dp[left][right] = 0;
    }
    if (dp[left][right] != -1)
      return dp[left][right];
    if (s[left] == s[right]) {
      dp[left][right] = 2 + helper(s, left + 1, right - 1, dp);
    } else {
      dp[left][right] = std::max(helper(s, left + 1, right, dp),
                                 helper(s, left, right - 1, dp));
    }
    return dp[left][right];
  }
};

// Solution 2: Bottom-Up Dynamic Programming
class Solution2 {
public:
  int longestPalindromeSubseq(string& s) {
    if (s.empty())
      return 0;

    const int N = s.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // all single chars are palindromic
    for (int i = 0; i < N; i++)
      dp[i][i] = 1;

    for (int l = 1; l < N; l++) {
      for (int i = 0; i < N - l; i++) {
        int j = i + 1;
        if ((j - i + 1) == 2) {
          dp[i][j] = 1 + (s[i] == s[j]);
        } else {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i+1][j-1] + 2;
          } else {
            dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
          }
        }
      }
    }
    return dp[0][N - 1];
  }
};


