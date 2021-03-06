// 96. Unique Binary Search Trees
/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
  int numTrees(int n) {
    vector<int> ans(n+1);
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        ans[i] += (ans[j] * ans[i - j - 1]);
      }
    }
    return ans[n];
  }

  int numTrees_recursion(int n) {
    if (n == 0) return 0;
    return getNumOfTrees(n);
  }

private:
  unordered_map<int, int> map;

  int getNumOfTrees(int n) {
    if (map.find(n) != map.end()) {
      return map[n];
    }

    if (n == 0 || n == 1)
      return 1;

    int cnt = 0;
    for (int i = 1; i < n; i++) {
      int leftcnt = getNumOfTrees(i - 1);
      int rightcnt = getNumOfTrees(n - i);
      cnt += leftcnt * rightcnt;
    }
    map[n] = cnt;
    return cnt;
  }
};

// dp  state: [i]   init: [0] = [1] = 1
//
// (1)  | (1)      (2)  |   (1)         (2)        (3)   |   (1)      (2)      (3)       (4)    |
//          (2)  (1)          (2)     (1)(1)     (2)           (3)   (1)(2)   (2)(1)    (3)
//
//  transform func: dp(i) = sum(dp(j) * dp(i - j - 1))
//  result: [n]
