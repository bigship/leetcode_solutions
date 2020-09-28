// 387. First Unique Character in a String
/*
 * Given a string, find the first non-repeating character in it and return its index.
 * If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.
*/

class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> map(26, 0);
    int ans = -1;
    for (int i = 0; i < s.length(); i++) {
      map[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
      if (map[s[i] - 'a'] == 1) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};

