// 707. Design Linked List

/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. 
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is 
a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to 
indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be 
    the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, 
    the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3

Note:

    All values will be in the range of [1, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in LinkedList library.

*/
class MyLinkedList {
public:
    MyLinkedList() {
      head = nullptr;
      length = 0;
    }
    
    int get(int index) {
      if (index >= length) return -1;
      if (index == 0) return head->val;
      
      ListNode *node = head;
      int cnt = 0;
      while (node) {
        if (cnt == index) 
          return node->val;
        node = node->next;
        cnt += 1;
      }
    }
    
    void addAtHead(int val) {
      ListNode *node = new ListNode(val);
      node->next = head;
      head = node;
      length += 1;
    }
    
    void addAtTail(int val) {
      ListNode *node = new ListNode(val);
      ListNode *cur = head;
      while (cur->next) {
        cur = cur->next;
      }
      cur->next = node;
      length += 1;
    }
    
    void addAtIndex(int index, int val) {
      if (index > length) return;
      if (index == length + 1) addAtTail(val);
      if (index == 0) addAtHead(val);
      
      int cnt = 0;
      ListNode *node = head;
      ListNode *prev = nullptr;
      while (node) {
        prev = node;
        node = node->next;
        cnt += 1;
        if (cnt == index) {
          ListNode *addOne = new ListNode(val);
          prev->next = addOne;
          addOne->next = node;
          length += 1;
          break;
        }
      }
    }
    
    void deleteAtIndex(int index) {
      if (index > length) return;
      int cnt = 0;
      ListNode *cur = head;
      ListNode *prev = nullptr;
      while (cur->next) {
        prev = cur;
        cur = cur->next;
        cnt += 1;
        if (cnt == index) {
          cur = cur->next;
          prev->next = cur;
          length--;
          break;
        }
      }
    }
private:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() {val = 0; next = nullptr;}
    ListNode(int v) {val = v; next = nullptr;}
  };
  ListNode *head;
  int length;
};