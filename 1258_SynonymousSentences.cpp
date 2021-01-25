// 1258. Synonymous Sentences
/*
 * Given a list of pairs of equivalent words synonyms and a sentence text, Return all possible synonymous sentences sorted lexicographically.
 *
Example 1:

Input:
synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
text = "I am happy today but was sad yesterday"
Output:
["I am cheerful today but was sad yesterday",
"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"]

Example 2:

Input: synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday"
Output: ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]

Example 3:

Input: synonyms = [["a","b"],["c","d"],["e","f"]], text = "a c e"
Output: ["a c e","a c f","a d e","a d f","b c e","b c f","b d e","b d f"]

Example 4:

Input: synonyms = [["a","QrbCl"]], text = "d QrbCl ya ya NjZQ"
Output: ["d QrbCl ya ya NjZQ","d a ya ya NjZQ"]

Constraints:
    0 <= synonyms.length <= 10
    synonyms[i].length == 2
    synonyms[i][0] != synonyms[i][1]
    All words consist of at most 10 English letters only.
    text is a single space separated sentence of at most 10 words.
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
  vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
    unordered_map<string, vector<string>> graph;
    for (vector<string>& pair : synonyms) {
      graph[pair[0]].push_back(pair[1]);
      graph[pair[1]].push_back(pair[0]);
    }

    set<string> res;
    queue<string> q;
    res.insert(text);
    q.push(text);
    while (!q.empty()) {
      string str = q.front();
      q.pop();
      vector<string> words = extractWord(out);

      for (int i = 0; i < words.size(); i++) {
        if (graph.count(words[i]) == 0)
          continue;
        for (string& synonym : graph[words[i]]) {
          words[i] = synonym;
          string newText = buildSentence(words);
          if (res.count(newText) == 0) {
            res.insert(newText);
            q.push(newText);
          }
        }
      }
    }
    return vector<string>(res.begin(), res.end());
  }

private:
  vector<string> extractWord(string& str) {
    vecctor<string> res;
    stringstream ss{str};
    string buf;
    char token = ' ';
    while (std::getline(ss, buf, token)) {
      res.push_back(buf);
    }
    return res;
  }

  string buildSentence(vector<string>& words) {
    string res;
    for (int i = 0; i < words.size(); i++) {
      res += words[i];
      if (i != words.size() - 1) {
        res += " ";
      }
    }
    return res;
  }
};

