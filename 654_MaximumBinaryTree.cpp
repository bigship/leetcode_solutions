// 654. Maximum Binary Tree
/*
 *  Given an integer array with no duplicates. A maximum tree building on this
 *  array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1

Note:

    The size of the given array will be in the range [1,1000].
*/

TreeNode *constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    auto it = max_element(nums.begin(), nums.end());
    TreeNode *root = new TreeNode(*it);
    vector<int> left(nums.begin(), it);
    vector<int> right(it+1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
}
