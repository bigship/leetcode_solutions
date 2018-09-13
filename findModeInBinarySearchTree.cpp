// 501. Find Mode in Binary Search Tree

/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2

 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

*/

// 用hashmap统计树中每个节点出现的次数. 利用一个helper函数, 递归每个节点
// 找到出现次数最多的节点, 往vector中push即可

class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    unordered_map<int, int> hash = {};
    vector<int> ret;
    helper(root, &hash);

    int max_value = INT_MIN;
    for (auto& t : hash) {
      if (t.second > max_value) {
        max_value = t.second;
      }
    }

    for (auto& t : hash) {
      if (t.second == max_value) {
        ret.push_back(t.first);
      }
    }

    return ret;
  }

private:
  void helper(TreeNode *root, unordered_map<int, int> *hash) {
    if (!root) return;
    if (hash->find(root->val) != hash->cend()) {
      (*hash)[root->val] += 1;
    } else {
      (*hash)[root->val] = 1;
    }
    helper(root->left, hash);
    helper(root->right, hash); 
  }
};