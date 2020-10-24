// 1400. Construct K Palindrome Strings
/*
 * Given a string s and an integer k. You should construct k non-empty palindrome
 * strings using all the characters in s.
   Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Example 4:

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string.
Both strings will be palindrome.

Example 5:

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.

Constraints:

    1 <= s.length <= 10^5
    All characters in s are lower-case English letters.
    1 <= k <= 10^5
*/

class Solution {
public:
  // 回文特点: 以中心呈镜像
  // 奇数长度, 则只有一个字符放中心
  // 偶数长度, 则每个字符都出现了偶数次
  // 统计出现了奇数次的字符, 如果超过了k则不可能使用全部的字符构建(会剩下一个奇数次的字符无法填充)
  bool canConstruct(string s, int k) {
    vector<int> map(26, 0);
    for (auto& ch : s) {
      map[ch - 'a']++;
    }
    if (s.length() < k)   // 整体长度小于k, 则没有足够的字符构建出k个回文
      return true;

    int oddcnt = 0;
    for (int i = 0; i < 26; i++) {
      if (map[i] % 2 == 1){
        cnt++;
        if (cnt > k)
          return false;
      }
    }
    return true;
  }
};



