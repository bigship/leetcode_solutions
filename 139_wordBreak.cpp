// 139. Word break
/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        helper(s, s.size(), wordDict, ans);
        return ans;
    }
private:
    // DFS TLE !!
    void helper(string str, size_t len, vector<string>& wordDict, bool& ans) {
        if (len == 0) {
            ans = true;
            return ;
        } else {
            for (auto& w : wordDict) {
                if (str.find(w) == 0)
                    helper(str.substr(w.size()), str.size() - w.size(), wordDict, ans);
            }
        }
    }

public:
    // Dynamic Programming
    bool wordBreakDP(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        int n = s.length();
        s = " " + s;  // s[1..n]
        vector<int> f(n+1, 0);
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (f[j] == 1) {
                    const string news = s.substr(j+1, i-j);  // s[j+1..i]
                    if (dict.count(news)) {
                        f[i] = 1;
                        break;
                    }
                }
            }
        }
        return f[n];
    }
};


int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //string s = "aaaaaab";
    vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    //cout << "ans: " << Solution().wordBreak(s, wordDict) << endl;
    cout << "ans: " << std::boolalpha << Solution().wordBreakDP(s, wordDict) << endl;
    return 0;
}
