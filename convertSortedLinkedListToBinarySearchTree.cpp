// 109. COnvert Sorted List to BInary Search Tree

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);

    ListNode *mid = findListMid(head);
    TreeNode *node = new TreeNode(mid->val);
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    return node;
  }
private:
  ListNode *findListMid(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow;
  }
};