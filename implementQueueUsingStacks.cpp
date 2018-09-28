// 232. Implement Queue using Stacks

/*
implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:
    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class MyQueueUsingStack {
public:
  MyQueue() {

  }

  void push(int x) {
    in.push(x);
  }

  int pop() {
    if (!out.empty()) {
      int v = out.top();
      out.pop();
      return v;
    } else {
      while (!in.empty()) {
        int v = in.top();
        in.pop();
        out.push(v);
      }
      int v = out.top();
      out.pop();
      return v;
    }
  }

  int peek() {
    if (!out.empty()) {
      int v = out.top();
      return v;
    } else {
      while (!in.empty()) {
        int v = in.top();
        in.pop();
        out.push(v);
      }
      int v = out.top();
      return v;
    }
  }

  bool empty() {
    return in.empty() && out.empty();
  }
private:
  stack<int> in;
  stack<int> out;
};

class MyQueueUsingVector {
public:
  MyQueue() {

  }

  void push(int x) {
    in.push_back(x);
  }

  int pop() {
    if (out.empty()) {
      out = vector<int>(in.rbegin(), in.rend());
      vector<int>().swap(in);
    }
    int value = out.back();
    out.pop_back();
    return value;
  }

  int peek() {
    if (out.empty()) {
      out = vector<int>(in.rbegin(), in.rend());
      vector<int>().swap(in);
    }
    int value = out.back();
    return value;
  }

  bool empty() {
    return in.empty() && out.empty();
  }
private:
  vector<int> in;
  vector<int> out;
};
