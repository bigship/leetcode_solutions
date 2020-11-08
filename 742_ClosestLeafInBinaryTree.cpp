// 742. Closest Leaf in a Binary Tree
/*
 * Given a binary tree where every node has a unique value, and a target key k,
 * find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree.
Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row.
The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.

Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.

Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.

Note:
    root represents a binary tree with at least 1 node and at most 1000 nodes.
    Every node has a unique node.val in range [1, 1000].
    There exists some node in the given binary tree for which node.val == k.
*/

class Solution {
public:
  int findClosestLeaf(TreeNode *root, int k) {
    unordered_map<TreeNode *, vector<TreeNode *>> graph;   // 邻接表
    TreeNode *start = nullptr;

    // 把树转换成图
    function<void(TreeNode *root, TreeNode *parent)> buildGraph = [&](TreeNode *root, TreeNode *parent) {
      if (!root) return ;
      if (root->val == k) start = root;
      if (parent) {
        graph[parent].push_back(root);
        graph[root].push_back(parent);
      }
      buildGraph(root->left, root);
      buildGraph(root->right, root);
    };
    buildGraph(root, nullptr);

    // start BFS
    unordered_set<TreeNode *> seen;
    queue<TreeNode *> q;
    q.push(start);
    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();
      if (!cur->left && !cur->right)
        return cur->val;
      seen.insert(cur);
      for (auto& nei:graph[cur]) {
        if (seen.find(nei) != seen.end())
          continue;
        q.push(nei);
      }
    }

    return -1;     // never reach here !
  }
};