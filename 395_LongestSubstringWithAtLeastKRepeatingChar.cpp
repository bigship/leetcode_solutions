// 395. Longest Substring with At least K Repeating Characters
/*
 *  Find the length of the longest substring T of a given string (consists of lowercase letters only)
 *  such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    if (s.size() == 0) return 0;
    vector<int> m(26, 0);
    for (int i = 0; i < s.size(); i++)
      m[s[i] - 'a']++;

    bool isValid = true;
    for (int i = 0; i < s.size(); i++) {
      if (m[s[i] - 'a'] < k) {
        isValid = false;
        break;
      }
    }
    if (isValid) return s.size();  // base case. the whole string is the answer.

    int left = 0, right = 0, result = 0;
    while (left < s.size()) {
      // find split point
      if (m[s[right] - 'a'] < k) {
        // recursively call on the left side
        result = std::max(result, longestSubstring(s.substr(left, right-left), k));
        left = right + 1;   // advance left to the next position of right
      }
      right++;
    }

    // left may not reach the end, so recursively call on the right side
    if (left < s.size())
      result = std::max(result, longestSubstring(s.substr(left), k));
    return result;
  }
};

