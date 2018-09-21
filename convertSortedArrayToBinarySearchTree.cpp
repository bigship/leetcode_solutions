// 108. COnvert Sorted Array to Binary Search Tree

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

// 充分利用平衡二叉树的性质: 根节点总是比左子节点大, 而比右子节点小. 因此sorted array的中间位置就是根节点值, 再递归左子树和右子树

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int>& nums) {
    return createNode(nums, 0, nums.size() - 1);
  }
private:
  TreeNode *createNode(vector<int>& nums, int left, int right) {
    TreeNode *node = nullptr;
    if (left <= right) {
      int mid = left + (right - left) / 2;
      node = new TreeNode(nums[mid]);
      node->left = createNode(nums, left, mid - 1);
      node->right = createNode(nums, mid + 1, right);
    }
    return node;
  }
};

