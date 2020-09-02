// 199. Binary Tree Right Side View
/*
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
class Solution {
public:
    // Solution: Level order traversal. For each level, we take the last value
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        vector<int> cur;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node) {
                    cur.push_back(node->val);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            if (cur.size() > 0) {
                ans.push_back(cur.back());
                vector<int>().swap(cur);
            }
        }
        return ans;
    }

    // Optimized version.
    // push right first, then left
    // For each level, there will be only one value needed.
    // The first node with the same level id will be used, the rest is useless.
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;   // TreeNode*, and the level id
        q.push({root, 0});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node.second >= ans.size()) {
                ans.push_back(node.first->val);
            }
            if (node.first->right) q.push({node.first->right, node.second + 1});
            if (node.first->left) q.push({node.first->left, node.second + 1});
        }
        return ans;
    }
};