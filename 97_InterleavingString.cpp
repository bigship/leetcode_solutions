// 97. Interleaving String
/*
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into
non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm

|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
*/

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }

    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return isInterleave(s1, 0, s2, 0, s3, 0, dp);
  }
private:
  bool isInterleave(string s1, string s2, string s3, vector<vector<int>>& dp) {
    // s1全部取完了, 此时就看s2从j开始的子串是否等于s3从k开始的子串
    if (i == s1.length()) return s2.substr(j) == s3.substr(k);

    // s2全部取完了, 此时看s1从i开始的字串是否等于s3从k开始的子串
    if (j == s2.length()) return s1.substr(i) == s3.substr(k);

    // dp数组做记忆化, 已经求解过的直接返回结果
    if (dp[i][j] >= 0) return dp[i][j] == 1 ? true : false;

    // general case
    // 从s1中取第i个字符, 如果它和s3的第k个字符相同, 继续递归从s1中取第i + 1个字符和s3的第k + 1个字符比较
    // 或者从s2中取第j个字符, 如果它和s3的第k个字符相同, 继续递归从s2中取第j + 1个字符和s3的第k + 1个字符比较
    bool ans = false;
    if (s3[k] == s1[i] && isInterleave(s1, i + 1, s2, j, s3, k + 1, dp) ||
        s3[k] == s2[j] && isInterleave(s1, i, s2, j + 1, s3, k + 1, dp)) {
      ans = true;
    }
    dp[i][j] = ans ? 1 : 0;
    return ans;
  }
};


