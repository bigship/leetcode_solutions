// 1089. Duplicate Zeros
/*
 * Given a fixed length array arr of integers, duplicate each occurrence of zero,
 * shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.
Do the above modifications to the input array in place, do not return anything from your function.


Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]


Note:

    1 <= arr.length <= 10000
    0 <= arr[i] <= 9
*/

class Solution {
public:
  // In-place的解法
  // 先计算有几个元素会被顶出原数组
  // 特殊情况, 有可能0会在最后一个位置, 这个时候不能再扩展填一个0
  // 从尾部开始写入, 这样就不会出现值被覆盖的问题. 原数组末尾的几个值是会被顶出去的
  void duplicateZeros(vector<int>& arr) {
    if (arr.empty()) return;
    int dups = 0;
    int n = arr.size() - 1;
    for (int left = 0; left <= n - dups; left++) {
      if (arr[left] == 0) {
        if (left == n - dups) {
          arr[n] = 0;
          n -= 1;
          break;
        }
        dups++;
      }
    }

    int last = n - dups;
    for (int i = last; i >= 0; i--) {
      if (arr[i] == 0) {
        arr[i+dups] = 0;
        dups--;
        arr[i+dups] = 0;
      } else {
        arr[i+dups] = arr[i];
      }
    }
  }
};

