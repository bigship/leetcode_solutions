// 366. Find Leaves of Binary Tree
/*
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves,
 * repeat until the tree is empty.

Example:

Input: [1,2,3,4,5]

          1
         / \
        2   3
       / \
      4   5

Output: [[4,5,3],[2],[1]]

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         /
        2

2. Now removing the leaf [2] would result in this tree:

          1

3. Now removing the leaf [1] would result in the empty tree:

          []

[[3,5,4],[2],[1]], [[3,4,5],[2],[1]], etc, are also consider correct answers since
per each level it doesn't matter the order on which elements are returned.
*/

class Solution {
public:
  // Solution: 深度优先搜索, 如果遇到叶子节点将其值加入cur中, 然后将叶子节点变为nullptr
  // 一轮dfs完成后所有叶子节点就都变为nullptr, 循环这个过程直到原Tree的root变为nullptr则完成
  // Caution: 由于要修改指针本身的值(将叶子节点改为nullptr), 因此传参时是传入指向root指针的地址
  // 即双重指针
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> ans;
    vector<int> cur;
    if (!root) return ans;
    while (root) {
      dfs(&root, cur);
      ans.push_back(cur);
      vector<int>().swap(cur);
    }
    return ans;
  }
private:
  void dfs(TreeNode **root, vector<int>& cur) {
    if (!(*root)) return ;
    if (!(*root)->left && !(*root)->right) {
      cur.push_back((*root)->val);
      *root = nullptr;
      return ;
    }
    dfs(&((*root)->left), cur);
    dfs(&((*root)->right), cur);
  }
};

