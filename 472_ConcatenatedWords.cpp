// 472. Concatenated Words
/*
 * Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
   A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
*/

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    std::unordered_set<string> dict;
    std::unordered_set<string> cache;
    int minlen = INT_MAX;
    for (auto& w : words) {
      minlen = std::min(minlen, (int)w.length());
      if (w.length() != 0)
        dict.insert(w);
    }

    for (auto& word : words) {
      if (canForm(word, dict, cache, minlen)) {
        ans.push_back(word);
      }
    }

    return ans;
  }
private:
    bool canForm(string& word, unordered_set<string>& dict,
                 unordered_set<string>& cache, int min) {
    if (cache.count(word))
      return true;
    for (int i = min; i <= word.length() - min; i++) {
      string left = word.substr(0, i);
      string right = word.substr(i);
      if (dict.count(left)) {
        if (dict.count(right) || canForm(right, dict, cache, min)) {
          cache.insert(word);
          return true;
        }
      }
    }
    return false;
  }
};


// Trie
//
