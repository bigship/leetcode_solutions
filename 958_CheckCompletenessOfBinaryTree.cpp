// 958. Check Completeness of a Binary Tree
/*
 * Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:

Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}),
and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:

Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
*
*/

class Solution {
public:
    // Level order traversal, keep all the node pointer including nullptr
    bool isCompleteTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<int *> arr;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *cur = q.front();
                if (cur)
                    arr.push_back(&(cur->val));
                else
                    arr.push_back(nullptr);
                q.pop();
                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            ++curlevel;
            if (curlevel == h) break;
        }
        auto it1 = std::find(arr.begin(), arr.end(), nullptr);
        auto it2 = arr.end() - 1;
        while (it2 != arr.begin()) {
            if (*it2 != nullptr)
                break;
            --it2;
        }
        return (it2 > it2) ? false : true;
    }

    // Time - O(n), Space - O(n)
    bool isCompleteTree2(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        bool hasSeen = false;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (!cur) hasSeen = true;
            else {
                if (hasSeen) return false;
            }
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
private:
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};



