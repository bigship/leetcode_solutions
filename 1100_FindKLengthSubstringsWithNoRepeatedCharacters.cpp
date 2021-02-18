// 1100. Find K-Length Substrings With No Repeated Characters
//
/* Given a string S, return the number of substrings of length K with no repeated characters.

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation:
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: S = "home", K = 5
Output: 0
Explanation:
Notice K can be larger than the length of S. In this case is not possible to find any substring.

Note:

    1 <= S.length <= 10^4
    All characters of S are lowercase English letters.
    1 <= K <= 10^4
 */

// Sliding Window
class Solution {
public:
  int numKLenSubstrNoRepeats(string S, int K) {
    if (S.length() < K) return 0;
    int left = 0, right = 0;
    int ans = 0;
    std::unordered_map<char, int> window;

    while (left < S.length() && right < S.length()) {
      while (right - left + 1 != K + 1) {
        window[S[right]]++;
        right++;
      }
      if (window.size() == K) {
        ans++;
      }
      window[S[left]]--;
      if (window[S[left]] == 0) {
        window.erase(S[left]);
      }
      left++;
    }
    return ans;
  }
};
