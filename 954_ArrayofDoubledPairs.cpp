// 954. Array of Doubled Pairs
/*
 * Given an array of integers arr of even length, return true if and only if it is possible to reorder it
 * such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false

Constraints:

0 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5
*/

class Solution {
public:
  // Greedy. 把数组按元素绝对值大小排序. 对于每一个位置上的元素val, 必须要有2 * val与之配对
  // 使用hashmap保存元素出现的次数, 遍历配对即可. 配对上了从cntmap中减少次数, 如果减为0了, 删除元素
  bool canReorderDoubled(vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
      return abs(a) < abs(b);
    });
    std::unordered_map<int, int> cntmap;
    for (auto& v : arr) {
      cntmap[v]++;
    }

    for (int i = 0; i < arr.size(); i++) {
      int curv = arr[i];
      if (cntmap.count(curv) == 0)
        continue;
      if (cntmap.count(2 * curv) == 0) {
        return false;
      }
      cntmap[2 * curv]--;
      cntmap[curv]--;
      if (cntmap[2 * curv] == 0) {
        cntmap.erase(2 * curv);
      }
      if (cntmap[curv] == 0) {
        cntmap.erase(curv);
      }
    }
    return true;
  }
};
