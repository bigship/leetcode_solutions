// 1461. Check If a String Contains All Binary Codes of Size K
/*
 * Given a binary string s and an integer k.

Return True if every binary code of length k is a substring of s. Otherwise, return False.

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11".
They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:

Input: s = "00110", k = 2
Output: true

Example 3:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.

Example 4:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:

Input: s = "0000000001011100", k = 4
Output: false

Constraints:
    1 <= s.length <= 5 * 10^5
    s consists of 0's and 1's only.
    1 <= k <= 20
*/
// Solution: 我们总共有2^k个不同的组合. 因此从左到右开始构建长度为k的substring,
// 将它们加入到hashset中去. 如果我们可以得到2^k个不同的组合, 则返回true否则返回false
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int totalCnt = 1 << k;
    unordered_set<string> got;
    if (s.length() < k)
      return false;
    for (int i = 0; i <= s.length() - k; i++) {
      string str = s.substr(i, k);
      if (got.count(str) == 0) {
        got.insert(str);
        totalCnt--;
        if (totalCnt == 0) {
          return true;
        }
      }
    }
    return false;
  }
};


