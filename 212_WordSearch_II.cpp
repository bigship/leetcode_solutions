// 212. Word Search II
/*
 * Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.
*/

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;
    TrieNode root;

    for (auto& word: words) {
      TrieNode *cur = &root;
      for (char c : word) {
        if (cur->children[c-'a'] == nullptr) {
          cur->children[c-'a'] = new TrieNode();
        }
        cur = cur->children[c-'a'];
      }
      cur->word = &word;
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        dfs(board, i, j, &root, ans);
      }
    }
    return ans;
  }
private:
  struct TrieNode {
    TrieNode() {
      word = nullptr;
      children = vector<TrieNode *>(26, nullptr);
    }

    ~TrieNode() {
      for (auto node : children) {
        delete node;
      }
    }
  };

  void dfs(vector<vector<char>>& board, int x, int y, TrieNode *root, vector<string>& ans) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#')
      return ;

    char curchar = board[x][y];
    TrieNode *node = root->children[curchar - 'a'];
    if (node == nullptr) {
      return ;
    }

    if (node->word) {
      ans.push_back(*(node->word));
      node->word = nullptr;
    }

    board[x][y] = '#';
    dfs(board, x + 1, y, node, ans);
    dfs(board, x - 1, y, node, ans);
    dfs(board, x, y + 1, node, ans);
    dfs(board, x, y - 1, node, ans);
    board[x][y] = curchar;
  }
};


