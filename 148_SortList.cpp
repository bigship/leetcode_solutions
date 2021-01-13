// 148. Sort List
/*
 * Given the head of a linked list, return the list after sorting it in ascending order.
   Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

// Time: O(nlogn), Space: O(n)
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    vector<int> arr;
    ListNode *p = head;
    while (p) {
      arr.push_back(p->val);
      p = p->next;
    }
    std::sort(arr.begin(), arr.end());
    p = head;
    int idx = 0;
    while (p) {
      p->val = arr[idx];
      p = p->next;
      idx++;
    }
    return head;
  }
};


// Time: O(nlogn), Space: O(1)
// Merge Sort. Always get O(nlogn) runtime complexity
class Solution2 {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
  }
private:
  ListNode *getMid(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow;
  }

  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1) p->next = l1;
    if (l2) p->next = l2;
    return dummy->next;
  }
};

