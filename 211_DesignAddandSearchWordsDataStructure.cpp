// 211. Design Add and Search Words Data Strucutre
/*
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
    word may contain dots '.' where dots can be matched with any letter.



Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

Constraints:

    1 <= word.length <= 500
    word in addWord consists lower-case English letters.
    word in search consist of  '.' or lower-case English letters.
    At most 50000 calls will be made to addWord and search.
*/

// 直接使用hashmap, 以长度为key保存单词
// 查询的时候根据待查词的长度去遍历每个单词, 逐位比较, 如果待查词对应位置为.
// 也可以通过比较.
class WordDictionary {
public:
  WordDictionary() {

  }

  void addWord(string word) {
    const int n = word.length();
    map[n].insert(word);
  }

  bool search(string word) {
    int n = word.length();
    if (map.find(n) != map.end()) {
      for (auto& str : map[n]) {
        int i = 0;
        while (i < n && str[i] == word[i] || word[i] == '.')
          i++;
        if (i == n)
          return true;
      }
    }
    return false;
  }
private:
  std::unordered_map<int, std::set<string>> map;
};

// 使用Trie 字典树
class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }

  void addWord(string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.length(); i++) {
      if (cur->children[word[i] - 'a'] == nullptr) {
        cur->children[word[i] - 'a'] = new TrieNode();
      }
      cur = cur->children[word[i] - 'a'];
    }
    cur->isWord = true;
  }

  bool search(string word) {
    return searchHelper(word, root);
  }

  class TrieNode {
  public:
    bool isWord = false;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
  };

private:
  TrieNode *root;

  bool searchHelper(string word, TrieNode *root) {
    TrieNode *cur = root;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++) {
          if (cur->children[j] != nullptr) {
            if (searchHelper(word.substr(i+1), cur->children[j]))
              return true;
          }
        }
        return false;
      }

      if (cur->children[word[i] - 'a'] == nullptr)
        return false;
      cur = cur->children[word[i] - 'a'];
    }
    return cur->isWord;
  }
};


