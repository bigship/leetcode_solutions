// 863. All Nodes Distance K in Binary Tree
/*
 * We are given a binary tree (with root node root), a target node, and an integer value K.
   Return a list of the values of all nodes that have a distance K from the target node.
   The answer can be returned in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]

Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:
    The given tree is non-empty.
    Each node in the tree has unique values 0 <= node.val <= 500.
    The target node is a node in the tree.
    0 <= K <= 1000.
*/

class Solution {
public:
  // 先将Tree结构转换为图, 转换中找到目标节点作为之后BFS的起点
  // 然后从start开始BFS搜索, 移动K步之后把节点加入答案中
  // BFS搜索时要保证每个节点只访问一次, 由unordered_set维护已访问的节点
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    TreeNode *start = nullptr;
    unordered_map<TreeNode *, vector<TreeNode *>> graph;

    // 将树转换成图
    function<void(TreeNode *, TreeNode *)> buildGraph = [&](TreeNode *root, TreeNode *parent) {
      if (!root) return;
      if (root->val == target->val) start = root;
      if (parent) {
        graph[parent].push_back(root);
        graph[root].push_back(parent);
      }
      buildGraph(root->left, root);
      buildGraph(root->right, root);
    };

    buildGraph(root, nullptr);

    vector<int> ans;
    unordered_set<TreeNode *> seen;
    queue<TreeNode *> q;
    seen.insert(start);
    q.push(start);

    int steps = 0;
    while (!q.empty() && steps <= K) {
      int n = q.size();
      while (n--) {
        TreeNode *node = q.front();
        q.pop();
        if (steps == K) {
          ans.push_back(node->val);
        }
        for (auto& nei : graph[node]) {
          if (seen.count(nei) != 0) continue;
          q.push(nei);
        }
        seen.insert(node);
      }
      steps++;
    }
    return ans;
  }
};


class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> rootMap;

    // 将每个节点的root保存下来, 存在hashmap中, key为当前节点, value是节点的父亲节点
    void buildRootMap(TreeNode* curNode, TreeNode* root) {
      if (!curNode) return;
      rootMap[curNode] = root;
      buildRootMap(curNode->left, curNode);
      buildRootMap(curNode->right, curNode);
    }

    // DFS. 对于每个节点都有3种方法可以移动, 从根走, 从左子树走, 从右子树走
    // 每移动一次距离K递减, 当K == 0时表示距离target为K的节点找到了, 加入答案
    void dfs(TreeNode *curNode, TreeNode *pre, int K, vector<int>& res) {
      if (!curNode) return;
      if (K == 0) {
        res.push_back(curNode->val);
        return;
      }
      // pre在这里的目的是不走回头路
      // 如果没有pre, 则下一层递归的时候会走回来 (例如: 本层可以往根走, 到了下一层又会从根走回来)
      //
      // 往根移动  (向上)
      if (pre != rootMap[curNode]) dfs(rootMap[curNode], curNode, K - 1, res);

      // 往左子树移动 (向下)
      if (pre != curNode->left) dfs(curNode->left, curNode, K - 1, res);

      // 往右子树移动  (向下)
      if (pre != curNode->right) dfs(curNode->right, curNode, K - 1, res);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
      buildRootMap(root, nullptr);
      vector<int> res;
      dfs(target, nullptr, K, res);
      return res;
    }
};


