// 72. Edit Distance
/*
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*
*/

class Solution {
public:
    // Recursion without memorization, TLE !!
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0)
            return word1.size() == 0 ? word2.size() : word1.size();

        int offset = 0;
        if (word1[offset] == word2[offset]) {
            return minDistance(word1.substr(offset+1), word2.substr(offset+1));
        }

        int d = minDistance(word1.substr(offset+1), word2);
        int u = minDistance(word1.substr(offset+1), word2.substr(offset+1));
        int i = minDistance(word1, word2.substr(offset+1));
        return std::min(d, std::min(u, i)) + 1;
    }

    int minDistance_dp(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> d(l1+1, vector<int>(l2+1, 0));

        for (int i = 0; i <= l1; ++i)
            d[i][0] = i;
        for (int j = 0; j <= l2; ++j)
            d[0][j] = j;

        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                int c = (word1[i-1] == word2[j-1]) ? 0 : 1;
                d[i][j] = std::min(d[i-1][j-1] + c, min(d[i][j-1], d[i-1][j]) + 1);
            }
        }
        return d[l1][l2];
    }

    int minDistance_recursionWithMen(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        d_ = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));
        return minDistance_recursionWithMem(word1, word2, l1, l2);
    }

    int minDistance_recursionWithMem(const string& word1, const string& word2, int l1, int l2) {
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        if (d_[l1][l2] >= 0) return d_[l1][l2];

        int ans;
        if (word1[l1-1] == word2[l2-1])
            ans = minDistance(word1, word2, l1-1, l2-1);
        else
            ans = min(minDistance_recursionWithMem(word1, word2, l1-1, l2-1),
                    min(minDistance_recursionWithMem(word1, word2, l1, l2-1),
                        minDistance_recursionWithMem(word1, word2, l1-1, l2))) + 1;
        return d_[l1][l2] = ans;
    }
private:
    vector<vector<int>> d_;
};



