// 290. Word Pattern
/*
 * Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false

Constraints:
    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lower-case English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.
*/

// Extract every word in string s
// Use two hashtables
// The first hashtable stores the pattern char to string mapping
// The second hashtable store the string to pattern char mapping
// Use two pointers to iterate both the pattern and s at the same time
// If any of the two hashtables have conflicts, we know it's false
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> pmap;
    unordered_map<string, char> smap;
    vector<string> strs;
    stringstream ss(s);
    string buf;
    char token = ' ';
    while (getline(ss, buf, token)) {
      strs.push_back(buf);
    }
    if (pattern.length() != strs.size())
      return false;

    int i = 0, j = 0;
    int n = pattern.length();
    while (i < n && j < n) {
      if (pmap.count(pattern[i]) == 0) {
        pmap[pattern[i]] = strs[j];
        if (smap.count(strs[j]) != 0)
          return false;
        smap[strs[j]] = pattern[i];
      } else {
        if (pmap[pattern[i]] != strs[j]) {
          return false;
        }
      }
      i++;
      j++;
    }
    return true;
  }
};



