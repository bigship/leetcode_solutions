// 500. Keyboard Row
/*
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image below.

Example:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:

    You may use one character in the keyboard more than once.
    You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    unordered_map<char, int> m;
    vector<string> rows = {{"qwertyuiop"}, {"asdfghjkl"}, {"zxcvbnm"}};
    for (int i = 0; i < rows.size(); i++) {
        for (auto& ch : rows[i]) {
            m[ch] = i;
            m[toupper(ch)] = i;
        }
    }
    vector<string> ans;
    for (auto& word : words) {
        int r = m[word[0]];
        bool same = true;
        for (int i = 1; i < word.size(); i++) {
            if (r != m[word[i]]) {
                same = false;
                break;
            }
        }
        if (same)
            ans.push_back(word);
    }
    return ans;
  }
};

