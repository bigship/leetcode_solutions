// 725. Split Linked List in Parts
/*
 * Given the head of a singly linked list and an integer k,
 * split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one.
This may lead to some parts being null.
The parts should be in the order of occurrence in the input list,
and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.

*/

class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode *> ans;
    int nodeCnt = getListNodeCount(head);
    int reminder = 0;
    int groupCount = 0;

    if (nodeCnt < k) {
      reminder = 0;
      groupCount = 1;
    } else {
      reminder = nodeCnt % k;
      groupCount = nodeCnt / k;
    }

    ListNode *cur = head;
    ListNode *prev = head;

    while (cur != nullptr) {
      int cnt = 0;
      while (cur != nullptr && cnt < groupCount - 1) {
        cnt++;
        cur = cur->next;
      }

      // add one extra node
      if (reminder > 0) {
        cur = cur->next;
        reminder--;
      }
      ListNode *next = cur->next;
      cur->next = nullptr;   // disconnect the list
      ans.push_back(prev);
      prev = next;
      cur = next;
    }

    while (ans.size() < k) {
      ans.push_back({});
    }
    return ans;
  }
private:
  int getListNodeCount(ListNode *head) {
    int cnt = 0;
    while (head) {
      cnt++;
      head = head->next;
    }
    return cnt;
  }
};




