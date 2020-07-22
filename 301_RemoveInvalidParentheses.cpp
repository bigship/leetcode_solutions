// 301. Remove Invalid Parentheses
/*
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]

Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Example 3:

Input: ")("
Output: [""]
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;  // num of '(' need to removed
        int r = 0;  // num of ')' need to removed

        for (const char ch : s) {
            l += (ch == '(');
            if (l == 0)
                r += (ch == ')');   // 没有被'('匹配到的')'
            else
                l -= (ch == ')');   // 遇到')'则l减1, 表示匹配了一个')'
        }

        vector<string> ans;
        dfs(s, 0, l, r, ans);

        // 如果没有在算法中做去重复, 可以最后再在vector中去重, 但去重要先排序, 效率较低
        // std::sort(ans.begin(), ans.end());
        // ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }

private:
    bool isValid(const string& s) {
        int cnt = 0;
        for (const char ch : s) {
            if (ch == '(') ++cnt;
            if (ch == ')') --cnt;
            if (cnt < 0) return false;  // 没有左括号可以匹配
        }
        return cnt == 0;                // 左右括号必须数量一致
    }

    void dfs(string& s, int start, int l, int r, vector<string>& ans) {
        if (l == 0 && r == 0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // Only remove the first parenthes if there are consecutive ones to avoid duplicates
            if (i != start && s[i] == s[i-1]) continue;  // tricky ! Or could just use hashtable to record the existence
            if (s[i] == '(' || s[i] == ')') {
                string curr = s;
                curr.erase(i, 1);
                if (r > 0 && s[i] == ')')
                    dfs(curr, i, l, r-1, ans);
                else if (l > 0 && s[i] == '(')
                    dfs(curr, i, l-1, r, ans);
            }
        }
    }
};

