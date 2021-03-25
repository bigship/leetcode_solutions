// 227. Basic Calculator II
/*
 * Given a string s which represents an expression, evaluate this expression and return its value.
   The integer division should truncate toward zero.

Example 1:

Input: s = "3+2*2"
Output: 7

Example 2:

Input: s = " 3/2 "
Output: 1

Example 3:

Input: s = " 3+5 / 2 "
Output: 5

Constraints:

    1 <= s.length <= 3 * 10^5
    s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    s represents a valid expression.
    All the integers in the expression are non-negative integers in the range [0, 231 - 1].
    The answer is guaranteed to fit in a 32-bit integer.
*/

// 可以在字符串最左侧添加一个'+', 它不会使得表达式的值发生改变
// 这样可将字符串分割成多个 <op, int> 操作符和操作数的对子
// 从左往右处理. 乘除的优先级高于加减, 需要用中间变量存储高优先级的结果

class Solution {
public:
  int calculate(string s) {
    int i = 0;
    return parseExpr(s, i);
  }
private:
  int parseExpr(const string& s, int& i) {
    char op = '+';
    long left = 0, right = 0;
    while (i < s.length()) {
      if (s[i] != ' ') {
        long n = parseNum(s, i);
        switch (op) {
          case '+': left += right; right = n; break;
          case '-': left += right; right = -n; break;
          case '*': right *= n; break;
          case '/': right /= n; break;
        }
        if (i < s.length()) {
          op = s[i];
        }
      }
      ++i;
    }
    return left + right;
  }

  long parseNum(const string& s, int& i) {
    long n = 0;
    while (i < s.length() && isdigit(s[i])) {
      n = 10 * n + (s[i++] - '0');
    }
    return n;
  }
};


