// 1209. Remove All Adjacent Duplicates in String II
/*
 * Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters
 * from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:

    1 <= s.length <= 10^5
    2 <= k <= 10^4
    s only contains lower case English letters.
*/
class Solution {
public:
  // Save the character c and its count to stack
  // If the next character c is the same as the last, increment count
  // Otherwise push a pair (1, c) into the stack
  string removeDuplicates(string s, int k) {
    vector<pair<int, char>> stack = {{0, '#'}};
    string ans;
    for (char& c : s) {
      if (stack.back().second != c) {
        stack.push_back({1, c});
      } else if (++stack.back().first == k) {
        stack.pop_back();
      }
    }
    for (auto& p : stack) {
      ans.append(p.first, p.second);
    }
    return ans;
  }
};

