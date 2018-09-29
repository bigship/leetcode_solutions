// 5. Longest Palindromic Substring

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/


// Dynamic programming
// S(i, j) = S(i+1, j-1)   if s[i+1] == s[j-1]
// base case: S(i, j) = 1  if s[i] == s[j] and j == i+1 
//            S(i, j) = 1  if i == j

// DP bottom-top time complexity: O(n^2), space complexity: O(n^2)

// DP
class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    int max_len = 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (i == j) {
          dp[i][j] = 1;
        } else {
          if (s[i] == s[j]) {
            if (j == i+1) {
              dp[i][j] = 1;
            } else {
              dp[i][j] = dp[i+1][j-1];
            }
          } else {
            dp[i][j] = 0;
          }
        }
        if ((dp[i][j] == 1) && (j-i+1 > max_len)) {
          max_len = j-i+1;
          ans = s.substr(i, max_len);
        }
      }
    }
    return ans; 
  }
};

// 中心扩展法. Note: 回文中心可以是一个字符也可以是两个, 需要各做一次
// Time complexity O(n^2), space complexity: O(1)
class Solution {
public:
  string longestPalindrome(string s) {
    int best_len = 0;
    int start = 0;
    for (int i = 0; i < s.length(); ++i) {
      int l1 = getLen(s, i, i);
      int l2 = getLen(s, i, i + 1);
      int l = max(l1, l2);      
      if (l > best_len) {
        best_len = l;
        start = i - (l - 1) / 2;
      }
    }
    return s.substr(start, best_len);
  }
private:
  int getLen(const string& s, int l, int r) {
    if (s[l] != s[r]) return 1;    
    while (l >= 0 && r <= s.length() - 1 && s[l] == s[r]) {
      --l;
      ++r;
    };
    return r - l - 1;
  }
};
