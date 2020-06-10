// 32. Longest Valid Parentheses

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
// 定义start记录合法括号串的起始位置.

class Solution {
public:
  int longestValidParentheses(string s) {
    int max_len = 0, start = 0;
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') st.push(i);
      else {
        if (st.empty()) {
          start = i + 1;
        } else {
          st.pop();
          if (st.empty()) {
            max_len = max(max_len, i - start + 1);
          } else {
            max_len = max(max_len, i - st.top());
          }
        }
      }
    }
    return max_len;
  }
};

