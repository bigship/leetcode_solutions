// 541. Reverse String II
/*
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string.
 * If there are less than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters,
 * then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]
*/
class Solution {
public:
  string reverseStr(string s, int k) {
    if (k == 1) return s;
    const int len = s.length();
    if (k >= len) {
      reverse(s, 0, len-1);
      return s;
    }

    reverse(s, 0, k-1);
    int left = 2*k, right = 2*k+k-1;
    while (true) {
      if (left >= len)    // 左边界超出, 不再反转直接break
        break;
      if (right >= len) { // 右边界超出, 反转剩下的所有字符
        reverse(s, left, len - 1);
        break;
      }
      reverse(s, left, right);  // 都没有超出边界, 反转区间内的字符
      left += 2 * k;
      right = left + k - 1;
    }
    return s;
  }
private:
  void reverse(string& s, int start, int end) {
    while (start < end) {
      std::swap(s[start++], s[end--]);
    }
  }
};

