// 25. Reverse Nodes in K group
/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
K is a positive integer and is less than or equal to the length of the linked list.

If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

*/

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *newHead = nullptr;
    ListNode *tail = nullptr;
    ListNode *cur = head;

    while (cur) {
      int cnt = 0;
      while (cnt < k && cur) {
        cur = cur->next;
        cnt++;
      }

      if (cnt == k) {
        ListNode *revHead = reverseKNodes(head, k);
        if (newHead == nullptr) {
          newHead = revHead;
        }
        if (tail != nullptr) {
          tail->next = revHead;
        }
        tail = head;
        head = cur;
      }
    }

    if (tail != nullptr) {
      tail->next = head;
    }

    return newHead == nullptr ? head : newHead;
  }
private:
  ListNode *reverseKNodes(ListNode *head, int k) {
    ListNode *newHead = nullptr;
    while (head && k > 0) {
      ListNode *next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
      k--;
    }
    return newHead;
  }
};
