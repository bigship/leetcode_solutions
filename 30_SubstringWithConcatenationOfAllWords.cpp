// 30. Substring with Concatenation of All Words
/* You are given a string, s, and a list of words, words, that are all of the same length. 
   Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and 
   without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/
class Solution {
public:
    vector<int> findSubString(string s, vector<string>& words) {
        vector<int> ans;
        if (s.size() == 0 || words.size() == 0) return ans;
        unordered_map<string, int> dict;
        initDict(dict, words);
        int w_size = words[0].size();
        int total_size = words.size() * w_size;
        if (s.size() < total_size) return ans;
        int j = 0;

        for (int i = 0; i <= s.size() - total_size; i++) {
            for (j = 0; j < words.size(); j++) {
                string sub = s.substr(i + j * w_size, w_size);
                if (dict.find(sub) != dict.end() && dict[sub] != 0) {
                    dict[sub]--;
                } else {
                    break;
                }
            }
            if (j != words.size()) {
                if (j == 0) continue;
                initDict(dict, words);
            } else {
                ans.push_back(i);
                initDict(dict, words);
            }
        }
        return ans;
    }
private:
    void initDict(unordered_map<string, int>& d, vector<string>& words) {
        d.clear();
        for (auto& word: words) {
            d[word]++;
        }
    }
};

 
