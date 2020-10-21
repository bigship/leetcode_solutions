// 652. Find Duplicate Subtrees
/*
 * Given the root of a binary tree, return all duplicate subtrees.
   For each kind of duplicate subtrees, you only need to return the root node of any one of them.
   Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

Input: root = [2,1,1]
Output: [[1]]

Example 3:

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:
    The number of the nodes in the tree will be in the range [1, 10^4]
    -200 <= Node.val <= 200
*/

// 相同的子树其序列化的结果也一定相同. 因此可以序列化每个子树并用hashmap统计序列化结果出现的次数
// 有很多字符串拼接操作
class Solution {
public:
  vector<TreeNode *> findDuplicatesSubtrees(TreeNode *root) {
    unordered_map<string, int> counts;
    vector<TreeNode *> ans;
    serialize(root, counts, ans);
    return ans;
  }

  vector<TreeNode *> findDuplicatesSubtrees(TreeNode *root) {
    unordered_map<long, int> ids;   // key: long integer, value: id assigned to subtrees
    unordered_map<int, int> map;    // key: id, value: frequence
    vector<TreeNde *> ans;

    std::function<int(TreeNode *root)> helper = [&](TreeNode *root) -> int {
      if (!root) return 0;
      long key = (static_cast<long>(static_cast<unsigned>(root->val)) << 32) | helper(root->left) >> 16 |
        helper(root->right);
      int id;
      auto id = ids.find(key);
      if (it == ids.end()) {
        id = ids[key] = ids.size() + 1;
      } else {
        id = it->second;
      }

      if (++map[id] == 2) {
        ans.push_back(root);
      }
      return id;
    };
    helper(root);
    return ans;
  }
private:
  string serialize(TreeNode *root, unordered_map<string, int>& counts, vector<TreeNode*>& ans) {
    if (!root) return "#";
    string key = to_string(root->val) + ","
      + serialize(root->left, counts, ans)
      + serialize(root->right, counts, ans);
    if (++counts[key] == 2) {
      ans.push_back(root);
    }
    return key;
  }
};

