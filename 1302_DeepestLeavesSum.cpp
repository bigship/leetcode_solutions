// 1302. Deepest Leaves Sum
/*
 * Given a binary tree, return the sum of values of its deepest leaves.

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

*/

// Level order travelsal
int deepestLeavesSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> levelOrder;
    vector<int> rowpath;
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *cur = q.front();
            q.pop();
            rowpath.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        levelOrder.push_back(rowpath);
        rowpath.clear();
    }
    vector<int> deepest = levelOrder.back();
    return std::accumulate(deepest.begin(), deepest.end(), 0);
}

// 递归, 先计算最高层数
int deepestLeavesSum_Recursive(TreeNode *root) {
    int height = getTreeHeight(root);
    int sum = 0;
    sumOfDeepestLeaves(root, 1, height, sum);
    return sum;
}

int getTreeHeight(TreeNode *root) {
    if (!root) return 0;
    return 1 + std::max(getTreeHeight(root->left), getTreeHeight(root->right));
}

void sumOfDeepestLeaves(TreeNode *root, int cur, int height, int& sum) {
    if (!root) return ;
    if (cur == height) {
        sum += cur->val;
        return ;
    } else {
        sumOfDeepestLeaves(root->left, cur + 1, height, sum);
        sumOfDeepestLeaves(root->right, cur + 1, height, sum);
    }
}


