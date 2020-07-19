// 3. Longest Substring without Repeating characters
/*
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1) return s.size();
        unordered_map<char, int> m;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = i;
            } else {
                i = m[s[i]] + 1;
                if (ans < m.size())
                    ans = m.size();
                m.clear();
                m[s[i]] = i;
            }
        }

        int n = m.size();
        return std::max(ans, n);
    }

    int lengthOfLongestSubstring2(string s) {
        std::set<int> m;
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        while (i < n && j < n) {
            if (m.count(s[j]) == 0) {
                m.insert(s[j++]);
                ans = std::max(ans, j - i);
            } else {
                m.erase(s[i++]);
            }
        }
        return ans;
    }

    int lengthOfLongestSubstring3(string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int start = 0;
        std::fill(last, last + ASCII_MAX, -1);
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= start) {
                max_len = std::max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return std::max((int)s.size() - start, max_len);
    }
};
