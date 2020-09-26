// 988. Smallest String Starting From Leaf
/*
 * Given the root of a binary tree, each node has a value from 0 to 25 representing the
 * letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is
lexicographically smaller than "aba". A leaf of a node is a node that has no children.)

Example 1:

Input: [0,1,2,3,4,3,4]
Output: "dba"

Example 2:

Input: [25,1,3,1,3,0,2]
Output: "adz"

Example 3:

Input: [2,2,1,null,1,0,null,0]
Output: "abc"

Note:

    The number of nodes in the given tree will be between 1 and 8500.
    Each node in the tree will have a value between 0 and 25.
*/

class Solution {
public:
  // Solution: 遍历每一条边, 遍历的同时与当前ans比较, 如果有更小的值就更新ans
  string smallestFromLeaf(TreeNode *root) {
    string cur;
    leafToRoot(root, cur);
    return ans;
  }
private:
  string dict = "abcdefghijklmnopqrstuvwxyz";
  string ans;

  void leafToRoot(TreeNode *root, string& cur)
    if (!root) return;
    if (!root->left && !root->right) {
      cur += dict[root->val];
      string tmp = cur;
      std::reverse(tmp.begin(), tmp.end());
      if (ans.length() != 0) {
        if (ans > tmp) {
          ans = tmp;
        }
      } else {
        ans = tmp;
      }
      return ;
    }
    cur += dict[root->val];
    leftToRoot(root->left, cur);
    if (root->left) cur.pop_back();
    leftToRoot(root->right, cur);
    if (root->right) cur.pop_back();
  }
};


