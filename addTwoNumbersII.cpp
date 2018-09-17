// 445. Add Two Numbers II

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

// Can't reverse link list. So use stack as a helper data structure

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> st1, st2;
    while (l1 || l2) {
      if (l1) {
        st1.push(l1->val);
        l1 = l1->next;
      }

      if (l2) {
        st2.push(l2->val);
        l2 = l2->next;
      }
    }

    ListNode *head = nullptr, *p = nullptr;
    int sum = 0, carry = 0;
    while (!st1.empty() || !st2.empty() || carry) {
      sum = carry;
      if (!st1.empty()) {
        int digit = st1.top();
        st1.pop();
        sum += digit;
      }

      if (!st2.empty()) {
        int digit = st2.top();
        st2.pop();
        sum += digit;
      }

      carry = sum / 10;
      p = new ListNode(sum%10);
      p->next = head;
      head = p;
    }

    return head;
  }
};