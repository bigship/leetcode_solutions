// 255. Verify Preorder Sequence in Binary Search Tree
/*
 * Given an array of numbers, verify whether it is the correct preorder traversal
 * sequence of a binary search tree.

You may assume each number in the sequence is unique.
Consider the following binary search tree:

     5
    / \
   2   6
  / \
 1   3

Example 1:

Input: [5,2,6,1,3]
Output: false

Example 2:

Input: [5,2,1,3,6]
Output: true

Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int start = 0;
    dfs(preorder, start, INT_MIN, INT_MAX);
    return start == preorder.size();
  }

private:
  // preorder 因此处理完根节点后, 先从左子树递归
  void dfs(vector<int>& preorder, int& start, int lower, int upper) {
    if (start >= preorder.size() || preorder[start] < lower || preorder[start] > upper) {
      return ;
    }

    int val = preorder[start++];
    dfs(preorder, start, lower, val);
    dfs(preorder, start, val, upper);
  }
};
