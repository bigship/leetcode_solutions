// 20. Valid Parentheses

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

class Solution {
public:
  bool isValid(const string& s) {
    int len = s.size();
    if (len == 0) return true;
    if (len % 2 != 0) return false;

    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < len; i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        st.push(s[i]);
      } else {
        char top = st.top();
        st.pop();
        if ((top == '(') && (s[i] != ')')) return false;
        if ((top == '[') && (s[i] != ']')) return false;
        if ((top == '{') && (s[i] != '}')) return false;
        if (top == '}' || top == ']' || top == ')') return false;
      }
    }
    return st.empty();
  }
};