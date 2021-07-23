// 1940. Longest Common Subsequence Between Sorted Arrays
/*
 * Given an array of integer arrays arrays where each arrays[i] is sorted in strictly increasing order,
 * return an integer array representing the longest common subsequence between all the arrays.

A subsequence is a sequence that can be derived from another sequence by deleting
some elements (possibly none) without changing the order of the remaining elements.

Example 1:

Input: arrays = [[1,3,4],
                 [1,4,7,9]]
Output: [1,4]
Explanation: The longest common subsequence in the two arrays is [1,4].
Example 2:

Input: arrays = [[2,3,6,8],
                 [1,2,3,5,6,7,10],
                 [2,3,4,6,9]]
Output: [2,3,6]
Explanation: The longest common subsequence in all three arrays is [2,3,6].

Constraints:

2 <= arrays.length <= 100
1 <= arrays[i].length <= 100
1 <= arrays[i][j] <= 100
arrays[i] is sorted in strictly increasing order.
*/

// 按数组长度对arrays数组排序, 最长公共子序列不会超过这里最短的数组
// 由于每个数组都是有序的, 因此拿最短的数组遍历, 依次在其他数组中做二分查找
// 如果都存在就加入答案中. 如果某个数组查不到, 就说明不属于公共子序列
class Solution {
public:
  vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
    vector<int> ans;
    if (arrays.empty()) return ans;
    if (arrays.size() == 1) return arrays[0];

    std::sort(arrays.begin(), arrays.end(), [](const vector<int>& a, const vector<int>& b) {
      return a.size() < b.size();
    });

    vector<int> a = arrays[0];
    for (int i = 0; i < a.size(); i++) {
      int target = a[i];
      bool foundAll = true;
      //cout << "target = " << target << endl;
      for (int j = 1; j < arrays.size(); j++) {
        auto it = std::lower_bound(arrays[j].begin(), arrays[j].end(), target);
        if (it == arrays[j].end() || *it != target) {
          foundAll = false;
          break;
        }
      }
      if (foundAll) {
        ans.push_back(a[i]);
      }
    }
    return ans;
  }

  // 解法2: 利用每个数组是严格有序的, 说明每个数组中的元素都是不重复的
  // 因此如果属于公共子序列, 则说明该数出现过n次. n表示arrays数组中数组的个数
  // 所以可以直接计数即可
  vector<int> longestCommomSubsequence2(vector<vector<int>>& arrays) {
    vector<int> ans;
    vector<int> cnts(101, 0);
    for (int i = 0; i < arrays.size(); i++) {
      for (int j = 0; j < arrays[i].size(); j++) {
        cnts[arrays[i][j]]++;
        if (cnts[arrays[i][j]] == arrays.size()) {
          ans.push_back(arrays[i][j]);
        }
      }
    }
    return ans;
  }
};


