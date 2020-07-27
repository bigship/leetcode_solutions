// 872. Leaf-Similar Trees
/* Consider all the leaves of a binary tree.  From left to right order,
 * the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:

    Both of the given trees will have between 1 and 200 nodes.
    Both of the given trees will have values between 0 and 200
*/

// 只考虑叶子节点, 实际上任何一种遍历方法都可以
class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> p1;
        vector<int> p2;
        postOrder(root1, p1);
        postOrder(root2, p2);
        return p1 == p2;
    }
private:
    void postOrder(TreeNode *root, vector<int>& p) {
        if (!root) return;
        postOrder(root->left, p);
        postOrder(root->right, p);
        if (!root->left && !root->right) {
            p.push_back(root->val);
        }
    }

    void postOrder_iter(TreeNode *root, vector<int>& p) {
        if (!root) return;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *n = s.top();
            s.pop();
            if (n) {
                if (!n->left && !n->right)
                    p.push_back(n->val);
                if (n->right) s.push(n->right);
                if (n->left) s.push(n->left);
            }
        }
    }
};

