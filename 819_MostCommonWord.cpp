// 819. Most common word
/* Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words.  It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.
Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:

Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.



Note:

    1 <= paragraph.length <= 1000.
    0 <= banned.length <= 100.
    1 <= banned[i].length <= 10.
    The answer is unique, and written in lowercase (even if its occurrences in
    paragraph may have uppercase symbols, and even if it is a proper noun.)
    paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
    There are no hyphens or hyphenated words.
    Words only consist of letters, never apostrophes or other punctuation symbols.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

void stringToLower(string& s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return ;
}

vector<string> tokenize(string& p) {
    int n = p.size();
    vector<string> words;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        while (isalpha(p[i])) ++i;
        if (i == n) {
            string s = p.substr(start, i);
            stringToLower(s);
            words.push_back(s);
            break;
        }

        if (ispunct(p[i]) || p[i] == ' ') end = i;
        //cout << p.substr(start, end) << ":";
        //cout << start << "," << end << " -->" << p.substr(start, end - start) << endl;
        string w = p.substr(start, end - start);
        stringToLower(w);
        words.push_back(w);
        while (ispunct(p[end]) || p[end] == ' ') ++end;
        start = end;
        i = start;
    }
    return words;
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    string ans = "";
    unordered_set<string> ban(banned.begin(), banned.end());
    vector<string> words = tokenize(paragraph);

    unordered_map<string, int> m;
    int maxtimes = 0;
    for (auto& s: words) {
        if (ban.count(s) == 0) {
            ++m[s];
            maxtimes = std::max(maxtimes, m[s]);
        }
    }

    auto it = m.begin();
    while (it != m.end()) {
        if (it->second == maxtimes) {
            ans = it->first;
            break;
        }
        ++it;
    }
    return ans;
}

int main() {
    vector<string> words;
    string para = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    string ans = mostCommonWord(para, banned);
    cout << ans << endl;
    return 0;
}
