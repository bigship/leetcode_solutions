// 1544. Make the String Great
/*
 * Given a string s of lower and upper case English letters.
   A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and remove them.
You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good.

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:

Input: s = "s"
Output: "s"

Constraints:

    1 <= s.length <= 100
    s contains only lower and upper case English letters.
*/
class Solution {
public:
  // Solution 1: Using Stack
  string makeGood(string s) {
    if (s.length() == 0) return s;
    string ans;
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
      if (!st.empty() && tolower(s[i]) == tolower(st.top()) && s[i] != st.top()) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    while (!st.empty()) {
      ans = st.top() + ans;
    }
    return ans;
  }

  // Solution 2: 原地构建
  string makeGood2(string s) {
    string ans;
    for (int i = 0; i < s.length(); i++) {
      if (ans.length() != 0 && ans.back() != s[i] && tolower(ans.back()) == tolower(s[i])) {
        ans.pop_back();
      } else {
        ans += s[i];
      }
    }
    return ans;
  }
};
