// 820. Short Encoding of Words
/*
 * A valid encoding of an array of words is any reference string s and array of indices indices such that:
    words.length == indices.length
    The reference string s ends with the '#' character.
    For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].

Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

Example 1:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

Example 2:

Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].

Constraints:
    1 <= words.length <= 2000
    1 <= words[i].length <= 7
    words[i] consists of only lowercase letters.
*/

// Solution 1: 先将所有单词加入hashset中, 尝试把每个单词的后缀从hashset中去掉
// 最后hashset中剩下来的单词就是组成encoding字符串的部分, 依次添加#即可
class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    std::unordered_set<string> hashset(words.begin(), words.end());
    for (auto word : words) {
      for (int i = 1; i < word.length(); i++) {
        hashset.erase(word.substr(i));
      }
    }

    int ans = 0;
    for (auto w : hashset) {
      ans += w.length() + 1;
    }
    return ans;
  }
};

// Solution2: 由于目的就是要去除单词的后缀, 我们可以倒过来从右到左构建
// 前缀树Trie. 遍历words数组, 将每个单词逆序加入到Trie中. 这样Trie的叶子节点
// 就代表了不包含后缀的单词
class Solution2 {
public:
  int minimumLengthEncoding(vector<string>& words) {
    TrieNode *trie = new TrieNode();
    std::unordered_map<TrieNode *, int> nodes;

    for (int i = 0; i < words.size(); i++) {
      string word = words[i];
      TrieNode *cur = trie;
      for (int j = word.length() - 1; j >= 0; j--) {
        cur = cur->get(word[j]);
      }
      nodes[cur] = i;
    }

    int ans = 0;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
      if (it->first->count == 0) {
        ans += words[it->first->get(it->first)].length() + 1;
      }
    }
    return ans;
  }

  class TrieNode {
    vector<TrieNode *> children;
    int count;

    TrieNode() {
      this->children = vector<TrieNode *>(26, nullptr);
      this->count = 0;
    }

    TrieNode *get(char c) {
      if (children[c - 'a'] == nullptr) {
        children[c - 'a'] = new TrieNode();
        count++;
      }
      return children[c - 'a'];
    }
  }
};
