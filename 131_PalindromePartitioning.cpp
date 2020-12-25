// 131. Palindrome Partitioning
/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]

Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.
*/
// 类似这种返回所有解的问题, 通常需要使用回溯法
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<string> cur;
    vector<vector<string>> ans;
    int start = 0;
    backtrack(ans, cur, s, start);
    return ans;
  }
private:
  void backtrack(vector<vector<string>>& ans, vector<string>& cur, string& s, int start) {
    // start索引到达字符串结尾了, 此时已经产生了所有的回文子串, 添加到ans中
    if (start >= s.length()) {
      ans.push_back(cur);
      return ;
    }

    // 从头开始遍历每个字符, 如果以start开头, 以end结尾的子串是回文串, 则添加到当前解cur中
    // 然后开始递归调用backtrack, 将start往前进一个.
    // 回溯的套路
    // 遍历索引
    // 满足条件, 做出选择
    // 递归调用, 起始索引 + 1
    // 回溯, 撤销上次的选择
    for (int end = start; end < s.length(); end++) {
      if (isPalindrome(s, start, end)) {
        cur.push_back(s.substr(start, end - start + 1));
        backtrack(ans, cur, s, end + 1);
        cur.pop_back();  // 回溯, 将上一个解pop出来
      }
    }
  }

  bool isPalindrome(string& s, int start, int end) {
    while (start < end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};


