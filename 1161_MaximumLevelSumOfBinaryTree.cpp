// 1161. Maximum Level Sum of a Binary Tree
/*
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.


Example 1:

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Note:

    The number of nodes in the given tree is between 1 and 10^4.
    -10^5 <= node.val <= 10^5
*/
// Level order traversal
int maxLevelSum(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> levelSum;
    int sum = 0;
    while (!q.empty()) {
        int num = q.size();
        for (int i = 0; i < num; ++i) {
            TreeNode *n = q.front();
            sum += n->val;
            q.pop();
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        levelSum.push_back(sum);
        sum = 0;
    }

    return max_element(levelSum.begin(), levelSum.end()) - levelSum.begin() + 1;
}


