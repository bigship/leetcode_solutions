// 341. Flatten Nested List Iterator
/*
 * Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].

Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].
*/

// 利用stack, 反向把vector中的NestedInteger入栈
class NestedIterator {
public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; i--) {
      sk.push(&nestedList[i]);
    }
  }

  int next() {
    int res = sk.top()->getInteger();
    sk.pop();
    return res;
  }

  // 保证栈顶总是Integer
  bool hasNext() {
    while (!sk.empty()) {
      if (sk.top()->isInteger()) {
        return true;
      } else {
        NestedInteger *curr = sk.top();
        sk.pop();
        for (int i = curr->getList().size() - 1; i >= 0; i--) {
          sk.push(&curr->getList().at(i));
        }
      }
    }
    return false;
  }
private:
  std::stack<NestedInteger *> sk;
};

