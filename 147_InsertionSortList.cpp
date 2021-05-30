// 147. Insertion Sort List
/*
 * Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head.
 */

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode dummy = ListNode(0);
    while (head) {
      if (dummy.next == nullptr) {
        dummy.next = new ListNode(head->val);
      } else {
        ListNode *first = dummy.next;
        ListNode *pre = nullptr;
        while (first) {
          if (first->val < head->val) {
            pre = first;
            first = first->next;
          } else {
            break;
          }
        }

        if (pre == nullptr) {
          ListNode *newinsert = new ListNode(head->val);
          ListNode *oldhead = dummy.next;
          newinsert->next = oldhead;
          dummy.next = newinsert;
        } else {
          ListNode *newinsert = new ListNode(head->val);
          pre->next = newinsert;
          newinsert->next = first;
        }
      }
      head = head->next;
    }
    return dummy.next;
  }
};




