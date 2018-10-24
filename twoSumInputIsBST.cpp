// 653. Two Sum IV - Input is a BST

/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum 
is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> elements;
    travalsTree(root, elements);
    int low = 0, high = elements.size() - 1;
    while (low < high) {
      if (elements[low] + elements[high] == k) return true;
      else if (elements[low] + elements[high] > k) high--;
      else low++;
    }
    return false;
  }
private:
  void travalsTree(TreeNode *root, vector<int>& nums) {
    if (!root) return;
    travalsTree(root->left, nums);
    nums.push_back(root->val);
    travalsTree(root->right, nums);
  }
};
