// 1003. Check If Word Is Valid After Substitutions
/*
 * Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t
into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright,
where t == tleft + tright. Note that tleft and tright may be empty.

Return true if s is a valid string, otherwise, return false.

Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.

Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

Example 4:

Input: s = "cababc"
Output: false
Explanation: It is impossible to get "cababc" using the operation.

Constraints:

    1 <= s.length <= 2 * 104
    s consists of letters 'a', 'b', and 'c'
*/

class Solution {
public:
  // 利用stack, 每次遇到c就看stack里最顶部的两个元素是不是b和a, 如果不是
  // 则返回false. 否则弹出最顶部的两个元素.
  // 如果不是c就入栈
  bool isValid(string s) {
    vector<char> stack;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != 'c') {
        stack.push_back(s[i]);
      } else {
        int n = stack.size();
        if (n < 2 || stack[n-1] != 'b' || stack[n-2] != 'a')
          return false;
        stack.pop_back();
        stack.pop_back();
      }
    }
    return stack.empty();
  }
};


