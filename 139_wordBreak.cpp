// 139. Word break
/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  // Dynamic Programming
  bool wordBreakDP(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    int n = s.length();
    s = " " + s;  // s[1..n]
    vector<int> f(n+1, 0);
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (f[j] == 1) {
          const string news = s.substr(j+1, i-j);  // s[j+1..i]
          if (dict.count(news)) {
            f[i] = 1;
            break;
          }
        }
      }
    }
    return f[n];
  }
};

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // vector转hashset, O(1)时间判断是否存在dict中
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return wordBreak(s, dict);
  }
private:
  unordered_map<string, bool> mem_;  // 记忆化, 保存求解过的解

  bool wordBreak(const string& s, const unordered_set<string>& dict) {
    if (mem_.count(s)) return mem_[s];   // 已经求解过了直接返回
    if (dict.count(s)) return mem_[s] = true;  // 特例, 整个单词刚好就在字典里, 返回true

    // 遍历每个分隔点
    for (int j = 1; j < s.length(); j++) {
      const string left = s.substr(0, j);
      const string right = s.substr(j);

      // 如果右边存在于字典, 且左边也可以分隔则表示找到了解
      if (dict.count(right) && wordBreak(left, dict))
        return mem_[s] = true;
    }

    // 如果每个分隔点都尝试了, 但找不到解, 则表示无解
    return mem_[s] = false;
  }
};


