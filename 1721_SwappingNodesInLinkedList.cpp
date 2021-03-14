// 1721. Swapping Nodes in a Linked List
/*
 * You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from
the beginning and the kth node from the end (the list is 1-indexed).

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/

// Solution: 双指针, 分别找到firstk节点和lastk节点, 交换它们的值即可
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    if (!head || !head->next) return head;
    ListNode *lastk = head;
    ListNode *firstk = head;
    int moveSteps = k - 1;
    while (firstk && moveStep != 0) {
      firstk = firstk->next;
      moveStep--;
    }

    ListNode *p = firstk;
    while (p->next) {
      p = p->next;
      lastk = lastk->next;
    }

    std::swap(firstk->val, lastk->val);
    return head;
  }
};

