// 1062. Longest Repeating Substring
/*
 * Given a string s, find out the length of the longest repeating substring.
 * Return 0 if no repeating substring exists.


 Example 1:
 Input: "abcd"
 Output: 0
 Explanation: There is no repeating substring

 Example 2:
 Input: "abbaba"
 Output: 2
 Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice

 Example 3:
 Input: "aabcaabdaab"
 Output: 3
 Explanation: The longest repeating substrings is "aab", which occurs 3 times

 Example 4:
 Input: "aaaaa"
 Output: 4
 Explanation: The longest repeating substring is "aaaa", which occurs twice
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
  // brute force: 产生每一个substr, 通过hashset来判断是否出现过
  // 出现过表示该substr是一个重复的字串, 计算长度并更新最大长度
  // O(n^2)
  int longestRepeatingSubstring(string S) {
    unordered_set<string> strset;
    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
      for (int j = i + 1; j <= S.length(); j++) {
        string sub = S.substr(i, j - i);
        if (strset.find(sub) == strset.end()) {
          strset.insert(sub);
        } else {
          int len = sub.length();
          ans = std::max(ans, len);
        }
      }
    }
    return ans;
  }

  int longestRepeatingSubstr_dp(string S) {
    int ans = INT_MAX;
    vector<vector<int>> dp(S.size() + 1, vector<int>(S.size() + 1), 0);
    for (int i = 1; i <= S.size(); i++) {
      for (int j = 1; j < i; j++) {
        if (S[i-1] == S[j - 1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};

int main() {
  string S = "aaaaa";
  cout << Solution().longestRepeatingSubstring(S) << endl;
  return 0;
}
