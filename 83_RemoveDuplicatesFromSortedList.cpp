// 83. Remove Duplicates from Sorted List
/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

*/

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    while (p && p->next) {
      if (p->val == p->next->val) {
        ListNode *tmp = p->next;
        p->next = tmp->next;
        continue;
      }
      p = p->next;
    }
    return head;
  }
};
