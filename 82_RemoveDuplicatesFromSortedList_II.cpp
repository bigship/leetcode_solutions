// 82. Remove Duplicates from Sorted List II
/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

class Solution {
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    dummy->next = head;
    ListNode *cur = head;
    if (!cur) return nullptr;
    ListNode *next = cur->next;
    if (!next) return cur;

    int dup = INT_MIN;
    while (cur && next) {
      if (cur->val == dup) {
        cur = next;
        next = next->next;
        prev->next = cur;
      } else if (cur->val != next->val) {
        prev = cur;
        cur = next;
        next = next->next;
      } else {
        dup = cur->val;
        prev->next = next->next;
        cur = prev->next;
        if (cur)
          next = cur->next;
      }
    }
    if (cur && cur->val == dup) {
      prev->next = cur->next;
    }
    return dummy->next;
  }

  // Recursion
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *p = head->next;
    if (head->val == p->val) {
      while (p && head->val == p->val) {
        ListNode *tmp = p;
        p = p->next;
        delete tmp;
      }
      delete head;
      return deleteDuplicates(p);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};


class Solution2 {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0, head);
    ListNode *p = &dummy;
    while (head) {
      if (head->next && head->val == head->next->val) {
        while (head->next && head->val == head->next->val) {
          head = head->next;
        }
        p->next = head->next;
      } else {
        p = p->next;
      }
      head = head->next;
    }
    return dummy.next;
  }
};

