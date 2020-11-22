// 109. Convert Sorted List to Binary Search Tree
/*
 * Given the head of a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST. For this problem, a height-balanced binary tree is
 * defined as a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [0]
Output: [0]

Example 4:

Input: head = [1,3]
Output: [3,1]

Constraints:
    The number of nodes in head is in the range [0, 2 * 104].
    -10^5 <= Node.val <= 10^5
*/

class Solution {
  // 先转化为数组, 然后取中点的值作为根节点, 然后左右递归
  TreeNode *sortedListToBST(ListNode *head) {
    vector<int> arr;
    ListNode *node = head;
    while (node) {
      arr.push_back(node->val);
      node = node->next;
    }
    return buildTree(arr, 0, arr.size() - 1);
  }
private:
  TreeNode *buildTree(vector<int>& arr, int left, int right) {
    if (left > right) return nullptr;
    int mid = (right - left) / 2 + left;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildTree(arr, left, mid - 1);
    root->right = buildTree(arr, mid + 1, right);
    return root;
  }
};


class Solution {
public:
  // 由于链表已经是有序的, 我们采用中序遍历的方式构建BST
  TreeNode *sortedListToBST(ListNode *head) {
    h = head;
    int len = listSize(head);
    return buildTree(0, len - 1);
  }
private:
  ListNode *h;

  // inorder traversal
  TreeNode *buildTree(int left, int right) {
    if (left > right) return nullptr;
    int mid = (right - left) / 2 + left;
    TreeNode *l = buildTree(left, mid - 1);   // 先构建左子树.
    TreeNode *n = new TreeNode(h->val);       // 构建当前节点. 此时h应该指向了中点
    n->left = l;
    h = h->next;                              // 要继续递归构建右子树. 此时应把h继续往后移动
    n->right = buildTree(mid + 1, right);
    return n;
  }

  int listSize(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }
};

