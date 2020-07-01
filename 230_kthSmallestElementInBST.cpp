// 230. Kth smallest element in a BST
/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.



Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?



Constraints:

    The number of elements of the BST is between 1 to 10^4.
    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

class Solution {
public:
    // BST, in-order traversal is sorted (small - big)
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int cnt = 0;
        int ans;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->next;
            }
            cur = s.top();
            s.pop();
            cnt++;
            if (cnt == k) {
                ans = cur->val;
                break;
            }
            cur = cur->right;
        }
        return ans;
    }
};

