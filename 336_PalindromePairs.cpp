// 336. Palindrome Pairs
/*
 * Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list,
 * so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); i++) {
      map[words[i]] = i;
    }

    for (auto it = map.begin(); it != map.end(); it++) {
      int curidx = it->second;

      // Case 1: directly reversed
      string reverseWord = it->first;
      std::reverse(reverseWord.begin(), reverseWord.end());
      if (map.find(reverseWord) != map.end() && map[reverseWord] != curidx) {
        ans.push_back({curidx, map[reverseWord]});
      }

      // case 2: valid prefix
      vector<string> validPrefix = validPrefixes(it->first);
      for (string prefix : validPrefix) {
        string reversed = prefix;
        std::reverse(reversed.begin(), reversed.end());
        if (map.find(reversed) != map.end()) {
          ans.push_back({curidx, map[reversed]});
        }
      }

      // case 3: valid suffix
      vector<string> validSuffix = validSuffixes(it->first);
      for (string suffix : validSuffix) {
        string reversed = suffix;
        std::reverse(reversed.begin(), reversed.end());
        if (map.find(reversed) != map.end()) {
          ans.push_back({map[reversed], curidx});
        }
      }
    }

    return ans;
  }
private:
  vector<string> validPrefixes(const string& word) {
    vector<string> res;
    for (int i = 0; i < word.length(); i++) {
      if (isPalindromeInRange(word, i, word.length() - 1)) {
        res.push_back(word.substr(0, i));
      }
    }
    return validPrefix;
  }

  vector<string> validSuffixes(const string& word) {
    vector<string> res;
    for (int i = 0; i < word.length(); i++){
      if(isPalindromeInRange(word, 0, i)) {
        res.push_back(word.substr(i+1));
      }
    }
    return res;
  }

  bool isPalindromeInRange(const string& word, int left, int right) {
    while (left < right) {
      if (word[left++] != word[right--]) {
        return false;
      }
    }
    return true;
  }
};



