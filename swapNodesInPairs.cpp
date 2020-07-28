// 24. Swap Nodes in Pairs

/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表调整指向的问题, 常用dummyHead的方法保存head指针
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head) return nullptr;
    if (head && head->next == nullptr) return head;

    ListNode *dummy = nullptr;
    ListNode *last = dummy;
    ListNode *prev = dummy;
    ListNode *cur = head;
    while (cur && cur->next) {
      prev = cur;
      cur = cur->next;
      if (last != nullptr) last->next = cur;

      prev->next = cur->next;
      cur->next = prev;
      swap(cur, prev);
      last = cur;
      if (dummy == nullptr) dummy = prev;
      cur = cur->next;
    }
    return dummy;
  }

  // swap value, instead of manipulating pointers
  ListNode* swapPairs2(ListNode *head) {
    if (!head) return nullptr;
    ListNode *first = head;
    ListNode *second = nullptr;
    if (first->next) second = first->next;
    else return first;

    bool exchange = true;
    while (second) {
      if (exchange) {
        std::swap(first->val, second->val);
        exchange = false;
      } else {
        exchange = true;
      }
      second = second->next;
      first = first->next;
    }
    return head;
  }
};
