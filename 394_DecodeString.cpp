// 394. Decode String
/*
 * Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square
brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there won't be input like 3a or 2[4].

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/

class Solution {
public:
  string decodeString(string s) {
    int pos = 0;
    return helper(pos, s);
  }
private:
  string helper(int& pos, string s) {
    int num = 0;          // 记录数字部分
    string word = "";
    for (; pos < s.size(); pos++) {
      char cur = s[pos];
      if (cur == '[') {   // 开始新的子问题
        string curstr = helper(++pos, s);
        for (; num > 0; num--)
          word += curstr;
      } else if (isdigit(cur)) {   // 数字可能有多位 使用乘10 + 当前位的技巧累加得到结果
        num = num * 10 + cur - '0';
      } else if (cur == ']') {     // 子问题结束
        return word;
      } else {          // 遇到字符就累加
        word += cur;
      }
    }
    return word;
  }
};
