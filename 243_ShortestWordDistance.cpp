// 243. Shortest Word Distance
/*
 * Given a list of words and two words word1 and word2,
 * return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
// Time: O(n), Space: O(1)
//
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int x = -1, y = -1;
    int ans = INT_MAX;

    for (int i = 0; i < words.size(); i++) {
      if (words[i] == word1) {
        x = i;
      }
      if (words[i] == word2) {
        y = i;
      }
      if (x != -1 && y != -1)
        ans = std::min(ans, abs(x - y));
    }
    return ans;
  }
};

