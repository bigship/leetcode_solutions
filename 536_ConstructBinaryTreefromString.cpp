// 536. Construct Binary Tree from String
/*
 * You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis.
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example 1:

Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]

Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]

Example 3:

Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]

Constraints:

    0 <= s.length <= 3 * 104
    s consists of digits, '(', ')', and '-' only.
*/

class Solution {
public:
  // Solution: 递归解法. 先解析出根节点的值(注意节点的值可能不止1位整数, 因此要一直累加)
  // 根据题意, 如果没有遇到反括号就一直往左子树添加. 遇到第一个反括号了表示左子树添加完毕
  // 接下来继续判断有没有遇到反括号, 只是这一次要一直往右子树添加
  // Example: 4(2(3)(1))(6(5))
  TreeNode *str2tree(string s) {
    int index = 0;
    return str2tree(s, index);
  }
private:
  TreeNode *str2tree(string& s, int& index) {
    if (index == s.length())
      return nullptr;

    auto num = parseInt(s, index);
    auto node = new TreeNode(num);

    if (index < s.length() && s[index] != ')')
      node->left = str2tree(s, ++index);
    if (index < s.length() && s[index] != ')')
      node->right = str2tree(s, ++index);

    ++index;
    return node;
  }

  int parseInt(string& s, int index) {
    int sign = s[index] == '-' ? std::stoi(s[index++] + string("1")) : 1;
    int num = 0;
    while (index < s.length() && isdigit(s[index])) {
      num = num * 10 + (s[index++] - '0');
    }
    return num * sign;
  }
};


