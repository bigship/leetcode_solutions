// 22. Generate Parentheses
/*
 *  Given n pairs of parentheses, write a function to generate all combinations
 *  of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;
        helper(0, 0, n, "", ans);
        return ans;
    }

private:
    void helper(int left, int right, int n, string str, vector<string>& ans) {
        if (left == n && right == n) {
            ans.push_back(str);
            return;
        }
        if (left < n) {
            helper(left+1, right, n, str+"(", ans);
        }
        if (right < n && right < left) {
            helper(left, right+1, n, str+")", ans);
        }
    }
};

