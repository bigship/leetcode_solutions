// 151. Reverse Words in a String
/* Given an input string, reverse the string word by word.



Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.



Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

class Solution {
public:
    // Too complex.
    string reverseWords(string s) {
        if (s.size() == 0) return "";
        vector<string> wordList = tokenize(s);
        std::reverse(wordList.begin(), wordList.end());
        string ans = "";
        for (auto& w : wordList) {
            if (allSpaces(w)) w = "";
            else trimSpaces(w);
            ans += (w + " ");
        }
        ans.pop_back();
        return ans;
    }

    // use stringstream for extract each word
    // 做分词可用stringstream
    string reverseWordsUsingStringStream(string s) {
        stringstream all(s);
        string word, ans = "";
        while (all >> word) {
            ans = word + " " + ans;
        }

        return ans.pop_back();
    }
private:
    bool allSpaces(string& s) {
        return (std::all_of(s.cbegin(), s.cend(), [](char c) { return c == ' '; }));
    }

    void trimSpaces(string& s) {
        int l = 0, r = s.size() - 1;
        while (s[l] == ' ' && l <= r) l++;
        while (s[r] == ' ' && r >= 0) r--;
        s = s.substr(l, r - l + 1);
    }

    vector<string> tokenize(string& s) {
        int l = 0;
        int r = s.size() - 1;
        if (l == r) return vector<string>(1, s);

        while (s[l] == ' ' && l < r) l++;
        while (s[r] == ' ' && r > 0) r--;

        if (l >= r) return vector<string>(1, s);
        vector<string> wordList;
        int wordStart = l, wordEnd = l;
        while (wordEnd <= r) {
            while (s[wordEnd] != ' ' && wordEnd <= r)
                wordEnd++;
            wordList.push_back(s.substr(wordStart, wordEnd - wordStart));
            wordStart = wordEnd;
            while (s[wordStart] == ' ')
                wordStart++;
            wordEnd = wordStart;
        }
        return wordList;
    }
};
