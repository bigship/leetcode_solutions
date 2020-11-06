// 76. Minimum Window Substring
/*
 * Given two strings s and t, return the minimum window in s which will contain all the characters in t.
 * If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Example 2:

Input: s = "a", t = "a"
Output: "a"

Constraints:

    1 <= s.length, t.length <= 105
    s and t consist of English letters.


Follow up: Could you find an algorithm that runs in O(n) time?
*/

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> map;
    for (auto& ch : t)
      map[ch]++;

    int left = 0, right = 0;
    int lower = -1, upper = -1;
    int ans = INT_MAX;
    int tmp = ans;

    while (right < s.length()) {
      char cur = s[right];
      if (map.find(cur) != map.end()) {
        map[cur]--;
        while (isValid(map)) {
          tmp = right - left + 1;
          if (ans > tmp) {
            ans = tmp;
            lower = left;
            upper = right;
          }
          char k = s[left];
          if (map.find(k) != map.end())
            map[k] += 1;
          left++;
        }
      }
      right++;
    }
    if (lower == -1 || upper == -1)
      return "";
    return s.substr(lower, upper - lower + 1);
  }
private:
  bool isValid(unordered_map<char, int>& map) {
    for (auto& item : map) {
      if (item.second > 0)
        return false;
    }
    return true;
  }
};
