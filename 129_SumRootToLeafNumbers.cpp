// 129. Sum Root to Leaf Numbers
/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int ans = 0;
        string str = "";
        vector<string> paths;
        dfs(root, str, paths);
        for (string& path : paths) {
            ans += std::stoi(path);
        }
        return ans;
    }
private:
    // DFS 一直append直到遇到叶子节点
    // 左子树处理完要pop掉最后一个值, 再去处理右子树
    // 右子树处理完也要pop掉最后一个值, 向上回溯
    void dfs(TreeNode *root, string& str, vector<string>& paths) {
        if (!root) return ;
        if (!root->left && !root->right) {
            str += root->val + '0';
            paths.push_back(str);
            return ;
        }
        str += (root->val + '0');
        if (root->left) {
            dfs(root->left, str, paths);
            str.pop_back();   // back track
        }
        if (root->right) {
            dfs(root->right, str, paths);
            str.pop_back();   // back track
        }
    }
};
