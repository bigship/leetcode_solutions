// 266. Palindrome Permutation
/*
 * Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false

Example 2:

Input: "aab"
Output: true

Example 3:

Input: "carerac"
Output: true
*/

// Solution: 构成回文的条件, 如果所有字符都出现了偶数次则一定可以组成回文
// 如果有字符出现了奇数次, 则只能有这样的一个字符. 否则无法构成回文
class Solution {
public:
  unordered_map<char, int> cntmap;
  for (auto& ch : s)
    cntmap[ch]++;

  int oddCnt = 0;
  for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
    if (it->second & 1 == 1)
      oddCnt++;
  }
  if (oddCnt == 0) return true;
  return oddCnt == 1;
};

