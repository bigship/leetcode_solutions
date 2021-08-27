// 522. Longest Uncommon Subsequence II
/*
 * Given an array of strings strs, return the length of the longest uncommon subsequence between them.
 * If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

Example 1:

Input: strs = ["aba","cdc","eae"]
Output: 3
Example 2:

Input: strs = ["aaa","aaa","aa"]
Output: -1
*/

class Solution {
public:
  int findLUSlength(vector<string>& strs) {
    std::sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
       return s1.length() > s2.length();
    });

    for (int i = 0; i < strs.size(); i++) {
      bool flag = true;
      for (int j = 0; j < strs.size(); j++) {
        if (i == j) continue;
        if (isSubsequence(strs[i], strs[j])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return strs[i].length();
      }
    }
    return -1;
  }
private:
  bool isSubsequence(string& x, string& y) {
    if (x.length() > y.length()) {
      return false;
    }
    int j = 0;
    for (int i = 0; i < y.length(); i++) {
      if (x[j] == y[i]) {
        j++;
      }
    }
    return j == x.length();
  }
};
