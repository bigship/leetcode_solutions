// 316. Remove Duplicate Letters
/*
 * Given a string s, remove duplicate letters so that every letter appears once and only once.
 * You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

Constraints:

    1 <= s.length <= 104
    s consists of lowercase English letters.
*/
// TLE !! 先产生不重复的字符串, 并对其排序
// 实际上就是求排序后的字符串的第一个全排列,
// 使得这个排列是原字符串的一个子序列即可
class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_set<char> set;
    for (auto& ch : s) {
      set.insert(ch);
    }
    string str = string(set.begin(), set.end());
    std::sort(str.begin(), str.end());
    do {
      if (isSubsequence(str, s))
        return str;
    } while (std::next_permutation(str.begin(), str.end()));
    return str;
  }
private:
  bool isSubsequence(string& sub, string& str) {
    if (sub.size() == 0) return true;
    if (str.size() == 0) return false;
    int s_idx = 0, t_idx = 0;
    while (t_idx < str.size()) {
      if (sub[s_idx] == str[t_idx]) {
        s_idx++;
        if (s_idx == sub.size())
          return true;
      }
      t_idx++;
    }
    return false;
  }
};

// 利用栈
// 先统计原字符串中每个字符出现的次数
// 重新遍历原字符串, 先把该字符出现的次数减1, 表示我们使用了该字符
// 如果这个字符已经使用过了, continue
// 如果当前字符比栈顶元素要小, 而且栈顶元素在之后还会遇到(通过判断它出现的次数), 于是需要pop掉栈顶元素
// 且此时要把used修改为未使用过
class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> map(26, 0);
    vector<int> used(26, 0);
    for (auto& ch : s)
      map[ch - 'a']++;

    string ans;
    for (int i = 0; i < s.length(); i++) {
      map[s[i] - 'a']--;  // 遍历到该位置了, 减少该位置下字符的次数
      if (used[s[i] - 'a']) continue;

      // 栈顶比当前的字符要大, 而且栈顶元素在之后还会再次遇到, 那么此时需要pop栈顶
      while (ans.length() > 0 && ans.back() > s[i] && map[ans.back() - 'a'] > 0) {
        used[ans.back() - 'a'] = 0; // 由于我们删除了这个字符, 所以要重新将其置为未使用过
        ans.pop_back();
      }
      ans += s[i];
      used[s[i] - 'a'] = 1;  // 标记为已使用过了
    }
    return ans;
  }
};


