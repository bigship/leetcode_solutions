// 1328. Break a Palindrome
/*
 * Given a palindromic string palindrome, replace exactly one character by any
 * lowercase English letter so that the string becomes the lexicographically smallest
 * possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"

Example 2:

Input: palindrome = "a"
Output: ""

Constraints:

    1 <= palindrome.length <= 1000
    palindrome consists of only lowercase English letters.
*/

class Solution {
public:
  // 从头开始遍历到中间位置
  // 如果不是'a', 就替换为'a', 跳出循环即可
  // 如果没有替换过, 表示都是'a'. 判断字符串的长度
  // 如果长度 > 1, 最后一个字符+1即可
  // 长度 == 1 , 无法替换
  string breakPalindrome(string palindrome) {
    int len = palindrome.length();
    for (int i = 0; i < len / 2; i++) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    if (len > 1) {
      palindrome[len - 1] += 1;
      return palindrome;
    }
    return "";
  }
};

