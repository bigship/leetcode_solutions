// 606. Construct String from Binary Tree
/*
 * You need to construct a string consists of parenthesis and integers from a
 * binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()".
And you need to omit all the empty parenthesis pairs that don't affect the
one-to-one mapping relationship between the string and the original binary tree.

Example 1:

Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".

Example 2:

Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping
relationship between the input and the output.
*/

class Solution {
public:
  string tree2str(TreeNode *t) {
    if (!t) return "";
    const string s = to_string(t->val);
    const string left = tree2str(t->left);
    const string right = tree2str(t->right);

    // 叶子节点可省略后续的括号, 返回本身
    if (!t->left && !t->right) return s;
    // 左子树不为空, 右子树为空, 可省略右子树的括号
    if (t->left && !t->right) return s + "(" + l + ")";
    // 一般形式为s(left)(right)
    return s + "(" + left + ")" + "(" + right + ")";
  }
};


