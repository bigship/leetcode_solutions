// 155. Min stack

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
public:
  MinStack() { m = INT_MAX; }

  void push(int x) {
    if (x <= m) {
      a.push_back(m);
      m = x;
    }
    a.push_back(x);
  }

  void pop() {
    int v = a.back();
    a.pop_back();
    if (v == m) {
      m = a.back();
      a.pop_back();
    }
  }

  int top() {
    return a.back();
  }

  int getMin() {
    return m;
  }
private:
  vector<int> a;
  int m;
}

