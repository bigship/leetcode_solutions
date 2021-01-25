// 369. Plus One Linked List
/*
 * Given a non-negative integer represented as a linked list of digits, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list.

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]

Example 2:

Input: head = [0]
Output: [1]

Constraints:
    The number of nodes in the linked list is in the range [1, 100].
    0 <= Node.val <= 9
    The number represented by the linked list does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    ListNode *a = reverseLinkedList(head);
    ListNode *b = addOne(a);
    return reverseLinkedList(b);
  }
private:
  ListNode *reverseLinkedList(ListNode *head) {
    ListNode *dummy = nullptr;
    while (head) {
      ListNode *cur = head->next;
      head->next = dummy;
      dummy = head;
      head = cur;
    }
    return dummy;
  }

  ListNode *addOne(ListNode *head) {
    int carry = 1;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (p) {
      int cur = carry + p->val;
      if (cur >= 10) {
        carry = 1;
      } else {
        carry = 0;
      }
      p->val = cur % 10;
      prev = p;
      p = p->next;
    }

    if (carry) {
      prev->next = new ListNode(carry);
    }
    return head;
  }
};

