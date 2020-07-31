// 92. Reverse Linked List II
/*
 * Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

// 回溯法
// 单链表没有prev指针无法往后走, 利用回溯模拟向后退
// 翻转过程类似数组的翻转, 左右指针向中间移动 直到它们相遇或彼此越过对方
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m , int n) {
        left = head;
        stop = false;
        recurseAndReverse(head, m, n);
        return head;
    }
private:
    ListNode *left;
    bool stop;

    void recurseAndReverse(ListNode *right, int m, int n) {
        if (n == 1)
            return;

        right = right->next;   // n没有减至1 right就一直往前走
        if (m > 1) {
            left = left->next; // m没有减至1 left就一直往前走
        }

        recurseAndReverse(right, m - 1, n - 1);  //  递归调用

        // 如果left和right相遇 或者right越过了left (由于m <= n, 所以left不走了但right可能还要继续走)
        // 就停止交换
        if (left == right || right->next == left) {
            stop = true;
        }

        // 如果可以交换 则交换left和right对应的值
        if (!stop) {
            std::swap(left->val, right->val);
            left = left->next;  // 交换完毕left前进一格
            // right则通过回溯往回走一格
        }
    }
};
