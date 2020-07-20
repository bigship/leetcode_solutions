// 23. Merge K sorted lists
/*
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

class Solution {
public:
    // Merge lists one by one. Time - O(kN), Space - O(1)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *p = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            p = mergeTwoSortedLists(p, lists[i]);
        }
        return p;
    }

    // Like merge sort. Divide and Conquer. Time - O(Nlogk)
    ListNode *mergeKLists_DAC(vector<ListNode *> &lists) {
        if (!lists.size()) return nullptr;
        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval*2) {
                lists[i] = mergeTwoSortedLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
private:
    ListNode *mergeTwoSortedLists(ListNode *p1, ListNode *p2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (p1 && p2) {
            int v1 = p1->val;
            int v2 = p2->val;
            if (p1 <= p2) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;
        return dummy->next;
    }
};


