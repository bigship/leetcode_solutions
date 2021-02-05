// 1740. Find Distance in a Binary Tree
/*
 * Given the root of a binary tree and two integers p and q,
 * return the distance between the nodes of value p and value q in the tree.
 * The distance between two nodes is the number of edges on the path from one to the other.
 *
 *
    The number of nodes in the tree is in the range [1, 104].
    0 <= Node.val <= 10^9
    All Node.val are unique.
    p and q are values in the tree.
  */
// BFS. 先建立图, 然后求两点间的距离
class Solution {
public:
  int findDistance(TreeNode* root, int p, int q) {
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    buildGraph(root, graph, p);
    std::queue<TreeNode *> que;
    que.push(start);
    unordered_set<TreeNode *> visited;
    int ans = 0;

    while (!que.empty()) {
      int n = que.size();
      for (int i = 0; i < n; i++) {
        TreeNode *node = que.front();
        que.pop();
        if (node->val == q) {
          return ans;
        }
        visited.insert(node);
        for (int j = 0; j < graph[node].size(); j++) {
          if (visited.count(graph[node][j]) == 0) {
            que.push(graph[node][j]);
          }
        }
      }
      ans++;
    }
    return ans - 1;
  }
private:
  TreeNode *start;

  void buildGraph(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>>& graph, int p) {
    if (!root) return;
    if (root->val == p) {
      start = root;
    }
    if (root->left) {
      graph[root].push_back(root->left);
      graph[root->left].push_back(root);
    }
    if (root->right) {
      graph[root].push_back(root->right);
      graph[root->right].push_back(root);
    }
    buildGraph(root->left, graph, p);
    buildGraph(root->right, graph, p);
  }
};

// DFS. 只需要知道两点分别距离root有多远即可
// 如果p和q都在root的同一边 则结果为abs(distance(root, q) - distance(root, q))
// 如果p和q分属root的不同边, 则结果为distance(root, p) + distance(root, q)
class Solution2 {
public:
  int findDistance(TreeNode* root, int p, int q) {
    int distance1 = 0, distance2 = 0;
    bool left1 = false, left2 = false;
    distance1 = helper(root, p, left1);
    distance2 = helper(root, q, left2);
    if (left1 != left2)
      return distance1 + distance2;
    return abs(distance1 - distance2);
  }
private:
  int helper(TreeNode *root, int target, bool& isLeft) {
    if (!root) return INT_MIN;
    int step = 0;
    if (root->val == target) {
      return step;
    }
    int left = helper(root->left, target, isLeft) + 1;
    int right = helper(root->right, target, isLeft) + 1;

    (left < 0) ? (isLeft = false) : (isLeft = true);
    return left < 0 ? right : left;
  }
};


