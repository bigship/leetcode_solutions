// 763. Partition Labels
/*
 * A string S of lowercase English letters is given. We want to partition this string
 * into as many parts as possible so that each letter appears in at most one part,
 * and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.
*/
class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    vector<pair<int, int>> m(26, {-1, -1});
    for (int i = 0; i < S.length(); i++) {
      char ch = S[i];
      if (m[ch - 'a'].first != -1) {
        m[ch - 'a'].second = i;
      } else {
        m[ch - 'a'].first = i;
        m[ch - 'a'].second = i;
      }
    }

    for (int i = 0; i < S.length(); i++) {
      char ch = S[i];
      int r = -1;
      int lower = m[ch - 'a'].first;
      int upper = m[ch - 'a'].second;
      for (int j = lower; j <= upper; j++) {
        if (m[S[j] - 'a'].second > m[ch - 'a'].second) {
          r = std::max(m[S[j] - 'a'].second, r);
          upper = r;
        }
      }
      if (r != -1) {
        ans.push_back(r - m[ch - 'a'].first + 1);
        i = r;
      } else {
        ans.push_back(upper - lower + 1);
        i = upper;
      }
    }
    return ans;
  }
};
