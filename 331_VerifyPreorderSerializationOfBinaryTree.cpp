// 331. Verify Preorder Serialization of a Binary Tree
/*
 * One way to serialize a binary tree is to use preorder traversal.
 * When we encounter a non-null node, we record the node's value.
 * If it is a null node, we record using a sentinel value such as '#'.
 *
 * For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.
*/

class Solution {
public:
  bool isValidSerialization(string preorder) {
    int slots = 1;
    int n = preorder.length();
    for (int i = 0; i < n; i++) {
      if (preorder[i] == ',') {
        --slots;
        if (slots < 0)
          return false;
        if (preorder[i-1] != '#')
          slots += 2;
      }
    }
    slots = (preorder[n-1] == '#') ? slots - 1 : slots + 1;
    return slots == 0;
  }
};
