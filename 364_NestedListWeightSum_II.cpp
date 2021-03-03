// 364. Nested List Weight Sum II
/*
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf,
now the weight is defined from bottom up. i.e.,
the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's at depth 1, one 2 at depth 2.

Example 2:

Input: [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
*/
// DFS先计算层数, 然后再DFS计算结果. 每次递归到下一层时depth - 1
class Solution {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int depth = getDepth(nestedList);
    return depthSum(nestedList, depth);
  }
private:
  int depthSum(vector<NestedInteger>& nestedList, int depth) {
    int ret = 0;
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger()) {
        ret += nestedList[i].getInteger() * depth;
      } else {
        ret += depthSum(nestedList[i].getList(), depth - 1);
      }
    }
    return ret;
  }

  int getDepth(vector<NestedInteger>& nestedList) {
    int ret = 1;
    for (int i = 0; i < nestedList.size(); i++) {
      if (!nestedList[i].isInteger()) {
        ret = std::max(1 + getDepth(nestedList[i].getList()), ret);
      }
    }
    return ret;
  }
};


class Solution2 {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    if (nestedList.empty()) return 0;

    int preSum = 0;
    int result = 0;
    std::queue<NestedInteger> queue;
    for (auto& nestedInt : nestedList) {
      queue.push(nestedInt);
    }

    while (!queue.empty()) {
      int n = queue.size();
      int levelSum = 0;
      for (int i = 0; i < n; i++) {
        NestedInteger ni = queue.front();
        queue.pop();
        if (ni.isInteger()) {
          levelSum += ni.getInteger();
        } else {
          for (auto& nestedInt : ni.getList())
            queue.push(nestedInt);
        }
      }
      preSum += levelSum;   // preSum不清0, 每次处理完一整层, 把结果加到result中
      result += preSum;     // 相当于把之前的层的结果重复加到最终结果中. 变相实现了level * 当前层的和
    }
    return result;
  }
};

