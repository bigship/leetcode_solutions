// 95. Unique Binary Search Trees II
/*
 * Given an integer n, generate all structurally unique BST's (binary search trees)
 * that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



Constraints:

    0 <= n <= 8
*/
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        const auto& ans = generateTrees(1, n);
        return ans;
    }
private:
    vector<TreeNode *> generateTrees(int l, int r) {
        if (l > r) return { nullptr };
        vector<TreeNode *> ans;

        // let every i be the root
        for (int i = l; i <= r; ++i) {
            // recursively generate left and right subtree
            for (TreeNode *left : generateTrees(l, i-1)) {
                for (TreeNode *right: generateTrees(i+1, r)) {
                    ans.push_back(new TreeNode(i));  // root
                    ans.back()->left = left;         // left
                    ans.back()->right = right;       // right
                }
            }
        }

        return ans;
    }
};

