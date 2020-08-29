// 1047. Remove All Adjacent Duplicates in String
/*
 * Given a string S of lowercase letters, a duplicate removal consists of choosing
 * two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made.
It is guaranteed the answer is unique.

Example 1:

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Note:

    1 <= S.length <= 20000
    S consists only of English lowercase letters.
*/
class Solution {
public:
  // One pass solution, Accepted
  // Greedy
  string removeDuplicates(string S) {
    string ans;
    for (int i = 0; i < S.length(); i++) {
      if (ans.length() != 0 && ans.back() == S[i]) {
        ans.pop_back();
      } else {
        ans.push_back(S[i]);
      }
    }
    return ans;
  }

  // Two pass solution, TLE !!
  // 使用stack, 虽然仍是O(n)的复杂度, 但生成最后的结果需要不断pop栈顶
  // 如果字符串非常长, pop栈顶也是一个O(n)时间, 也就是需要遍历两次
  // 会超时
  string removeDuplicates(string S) {
    stack<char> st;
    if (S.length() != 0)
      st.push(S[0]);
    for (int i = 1; i < S.length(); i++) {
      if (!st.empty() && st.top() == S[i]) {
        st.pop();
      } else {
        st.push(S[i]);
      }
    }

    string ans;
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }
    return ans;
  }
};
