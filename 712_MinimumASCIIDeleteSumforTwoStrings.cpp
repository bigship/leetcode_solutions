// 712. Minimum ASCII Delete sum for two strings
/*
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Note:
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
*/
// 转化为把s1和s2都变为空串的最小代价
class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    const int l1 = s1.length();
    const int l2 = s2.length();
    m_ = vector<vector<int>>(l1+1, vector<int>(l2+1, INT_MAX));
    return dp(s1, l1, s2, l2);
  }
private:
  vector<vector<int>> m_;

  int dp(const string& s1, int i, const string& s2, int j) {
    if (i == 0 && j == 0) return 0;  // 全部都为空串了, 直接返回0
    if (m_[i][j] != INT_MAX) return m_[i][j];  // 记忆化
    if (i == 0) // s1为空串了
      return m_[i][j] = dp(s1, i, s2, j - 1) + s2[j - 1];
    if (j == 0) // s2为空串了
      return m_[i][j] = dp(s1, i - 1, s2, j) + s1[i - 1];
    if (s1[i-1] == s2[j-1]) // 字符相同
      return m_[i][j] = dp(s1, i-1, s2, j-1);
    return m_[i][j] = min(dp(s1, i-1, s2, j) + s1[i-1], dp(s1, i, s2, j-1) + s2[j-1]);
  }
};
