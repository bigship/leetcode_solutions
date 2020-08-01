// 208. Implement Trie (Prefix Tree)
/*
 * Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
*/

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;      // 标记完整单词
    }

    bool search(string word) {
        TreeNode *node = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return node->isWord;     // 必须要是完整单词
    }

    bool startsWith(string prefix) {
        TreeNode *node = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int idx = prefix[i] - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return true;            // 只是前缀, 不需要是完整单词
    }
private:
    class TrieNode {
    public:
        vector<TrieNode *> children;     // 26个字符, 每个字符一个节点 26叉树
        bool isWord;
        string word;
        TrieNode() {
            children = vector<TrieNode *>(26, nullptr);
            isWord = false;
            word = "";
        }
    };

    TrieNode *root;
};

