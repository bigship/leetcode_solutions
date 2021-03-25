// 870. Advantage Shuffle
/*
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
   Return any permutation of A that maximizes its advantage with respect to B.

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

Note:

    1 <= A.length = B.length <= 10000
    0 <= A[i] <= 10^9
    0 <= B[i] <= 10^9
*/

// Greedy.
// 对A排序, 由于A中可能存在重复的值, 这里使用multiset作为辅助数据结构
// 然后遍历B, 看A中当前的最大值是否大于B[i]. 如果成立, 则需要找一个满足大于B[i]且最小的值
// 如果A中当前最大的值都不能满足大于B[i], 则表示A中没有任何值可以满足, 此时就把A中的最小值选出来
// 这样其他的值还有可能继续满足条件
// C++中的upper_bound是找到第一个严格大于目标值的位置
class Solution {
public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    std::multiset<int> s(A.begin(), A.end());
    for (int i = 0; i < B.size(); i++) {
      auto it = *s.rbegin() > B[i] ? s.upper_bound(B[i]) : s.begin();
      A[i] = *it;
      s.erase(it);
    }
    return A;
  }
};

