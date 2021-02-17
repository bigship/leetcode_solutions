// 159. Longest Substring with At Most Two Distinct Characters
/*
 * Given a string s , find the length of the longest substring t that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

// Sliding window
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int left = 0, right = 0;
    const int len = s.length();
    int curlen = 0;
    int maxlen = 0;
    unordered_map<char, int> cntmap;

    while (left < len && right < len) {
      cntmap[s[right]]++;
      while (cntmap.size() > 2) {
        cntmap[s[left]]--;
        if (cntmap[s[left]] == 0) {
          cntmap.erase(s[left]);
        }
        left++;
        curlen--;
      }
      curlen = right - left + 1;
      maxlen = std::max(maxlen, curlen);
      right++;
    }
    return maxlen;
  }
};

