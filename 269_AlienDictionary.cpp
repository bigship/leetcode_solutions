// 269. Alien Dictionary
/*
 * There is a new alien language that uses the English alphabet.
 * However, the order among letters are unknown to you.

You are given a list of strings words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language, and return it.
If the given input is invalid, return "".
If there are multiple valid solutions, return any of them.

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"

Example 2:

Input: words = ["z","x"]
Output: "zx"

Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

Constraints:
    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists of only lowercase English letters.
*/
class Solution {
public:
  string alienOrder(vector<string>& words) {
    if (words.empty()) return "";
    unordered_map<char, int> indegree;
    unordered_map<char, unordered_set<char>> graph;

    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].size(); j++) {
        char c = words[i][j];
        indegree[c] = 0;
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      string cur = words[i];
      string next = words[i + 1];
      int len = min(cur.length(), next.length());
      for (int j = 0; j < len; j++) {
        if (cur[j] != next[j]) {
          unordered_set<char> set = graph[cur[j]];
          if (set.find(next[j]) == set.end()) {
            graph[cur[j]].insert(next[j]);
            indegree[next[j]]++;
          }
          break;
        }
        if (j == len - 1 && cur.length() > next.length())
          return "";
      }
    }

    string ans;
    queue<char> q;
    for (auto& e : indegree) {
      if (e.second == 0) {
        q.push(e.first);
      }
    }

    while (!q.empty()) {
      char cur = q.front();
      q.pop();
      ans += cur;
      if (graph[cur].size() != 0) {
        for (auto& e : graph[cur]) {
          indegree[e]--;
          if (indegree[e] == 0) {
            q.push(e);
          }
        }
      }
    }

    return ans.length() == indegree.size() ? ans : "";
  }
};

