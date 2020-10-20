// 716. Max Stack

/*
Design a max stack that supports push, pop, top, peekMax and popMax.
    push(x) -- Push element x onto stack.
    pop() -- Remove the element on top of the stack and return it.
    top() -- Get the element on the top.
    peekMax() -- Retrieve the maximum element in the stack.
    popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements,
    only remove the top-most one.

Example 1:

MaxStack stack = new MaxStack();
stack.push(5);
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5

Note:

    -1e7 <= x <= 1e7
    Number of operations won't exceed 10000.
    The last four operations won't be called when stack is empty.
*/

// peekMax - O(n), popMax - O(n)
class MaxStack {
public:
  MaxStack() {

  }

  void push(int x) {
    st.push_front(x);
  }

  int pop() {
    int v = st.front();
    st.pop_front();
    return v;
  }

  int top() {
    return st.front();
  }

  int peekMax() {
    return *(std::max_element(st.begin(), st.end()));
  }

  int popMax() {
    int m = peekMax();
    int index = 0;
    for (; index < st.size(); index++) {
      if (st[index] == m) {
        break;
      }
    }
    st.erase(st.begin() + index);
    return m;
  }
private:
  deque<int> st;
};


// Doublely linked list + map
class MaxStack {
public:
  MaxStack() {

  }

  void push(int x) {
    sk.push_back(x);
    m[x].push_back(--sk.end());
  }

  int pop() {
    int v = sk.back();
    m[v].pop_back();
    if (m[v].empty())
      m.erase(v);
    return v;
  }

  int top() {
    return sk.back();
  }

  int peekMax() {
    return m.rbegin()->first;
  }

  int popMax() {
    int v = peekMax();
    auto it = m[v].back();
    sk.erase(it);
    m[v].pop_back();
    if (m[v].empty())
      m.erase(v);
  }
private:
  std::list<int> sk;
  std::map<int, std::vector<std::list<int>::iterator>> m;
};
