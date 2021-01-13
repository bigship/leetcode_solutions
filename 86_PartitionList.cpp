// 86. Partition List
/*
 * Given the head of a linked list and a value x,
 * partition it such that all nodes less than x come before nodes greater than or equal to x.
   You should preserve the original relative order of the nodes in each of the two partitions.
 */

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *beforeHead = new ListNode(0);
    ListNode *before = beforeHead;
    ListNode *aferHead = new ListNode(0);
    ListNode *after = afterHead;

    while (head) {
      if (head->val < x) {
        before->next = head;
        before = before->next;
      } else {
        after->next = head;
        after = after->next;
      }
      head = head->next;
    }
    after->next = nullptr;
    before->next = afterHead->next;
    return beforeHead->next;
  }
};
