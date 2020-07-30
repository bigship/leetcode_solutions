// 328. Odd Even Linked List
/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL


Constraints:

    The relative order inside both the even and odd groups should remain as it was in the input.
    The first node is considered odd, the second node even and so on ...
    The length of the linked list is between [0, 10^4].
*/

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return nullptr;
        ListNode *p = head;
        ListNode *q = nullptr;
        if (p->next) q = p->next;
        else return head;
        if (!q->next) return head;

        // We have at least 3 nodes
        ListNode *evenHead = q;
        while (q && q->next) {
            ListNode *m = q->next;
            p->next = m;
            q->next = m->next;
            p = m;
            q = m->next;
        }
        p->next = evenHead;
        return head;
    }
};


