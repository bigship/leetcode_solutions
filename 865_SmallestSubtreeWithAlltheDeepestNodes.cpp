// 865. Smallest Subtree with all the deepest nodes
//
/* Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
   A node is deepest if it has the largest depth possible among any node in the entire tree.

   The subtree of a node is that node, plus the set of all descendants of that node.
   Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

   Input: [3,5,1,6,2,0,8,null,null,7,4]
   Output: [2,7,4]
   Explanation:

                 3
               /   \
              5     1
             / \   / \
            6   2 0   8
               / \
              7   4

  We return the node with value 2, colored in yellow in the diagram.
  The nodes colored in blue are the deepest nodes of the tree.
  The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
  The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
  Both the input and output have TreeNode type.

Note:
    The number of nodes in the tree will be between 1 and 500.
    The values of each node are unique.
*/
// 返回拥有最深叶子节点的最近公共祖先
// 必须是最深, 如果左右子树的深度不同, 则答案为左子树或右子树
// 如果左右子树深度相同, 答案就是root
class Solution {
public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    return helper(root).second;
  }
private:
  // 使用pair来记录当前的节点深度, 以及左右子节点的最近公共祖先
  pair<int, TreeNode *> helper(TreeNode *root) {
    if (!root) return {-1, nullptr};   // 节点为空, 深度记为-1
    auto l = helper(root->left);       // 递归求解左节点
    auto r = helper(root->right);      // 递归求解右节点
    int dl = l.first;  // 左节点深度
    int dr = r.first;  // 右节点深度
    return {std::max(dl, dr) + 1, dl == dr ? root : (dl > dr) ? l.second : r.second};
  }
};


