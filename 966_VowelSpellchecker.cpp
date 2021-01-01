// 966. Vowel Spellchecker
/*
 * Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

    Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
        Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
        Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
        Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
    Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive),
    then the query word is returned with the same case as the match in the wordlist.
        Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
        Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
        Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitlization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.

Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

Note:

    1 <= wordlist.length <= 5000
    1 <= queries.length <= 5000
    1 <= wordlist[i].length <= 7
    1 <= queries[i].length <= 7
    All strings in wordlist and queries consist only of english letters.
*/

class Solution {
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    for (auto word : wordlist) {
      perfectMatch.insert(word);

      string lower = word;
      std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char x) -> unsigned char {
        return std::tolower(x);
      });

      // return the first one, so check existence
      if (cap.count(lower) == 0)
        cap[lower] = word;

      // return the first one, so check existence
      string vowlized = devowel(lower);
      if (vow.count(vowlized) == 0)
        vow[vowlized] = word;
    }

      vector<string> ans;
      for (auto& query : queries)
        ans.push_back(doCheck(query));
      return ans;
  }
private:
  std::unordered_set<string> perfectMatch;
  std::unordered_map<string, string> cap;
  std::unordered_map<string, string> vow;

  bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  string devowel(string word) {
    string ret;
    for (auto& c : word) {
      ret += (isVowel(c) ? '*' : c);
    }
    return ret;
  }

  string doCheck(string query) {
    if (perfectMatch.count(query) != 0)
      return query;

    string low = query;
    std::transform(low.begin(), low.end(), low.begin(), [](unsigned char x) -> unsigned char {
      return std::tolower(x);
    });
    if (cap.count(low) != 0)
      return cap[low];

    string vowel = devowel(low);
    if (vow.count(vowel) != 0)
      return vow[vowel];

    return "";
  }
};


