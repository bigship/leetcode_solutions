// 941. Valid Mountain Array
/*
 * Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < A[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]
Output: false

Example 2:

Input: arr = [3,5,5]
Output: false

Example 3:

Input: arr = [0,3,2,1]
Output: true

Constraints:
    1 <= arr.length <= 104
    0 <= arr[i] <= 104
*/

class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    const int len = arr.size();
    int i = 0;

    // 上升, 找拐点
    while (i + 1 < len && arr[i] < arr[i+1])
      i++;

    // 拐点不能在第一个或最后一个(不能是严格单调的)
    if (i == 0 || i == len - 1)
      return false;

    // 下降
    while (i + 1 < len && arr[i] > arr[i+1])
      i++;

    // 必须走到底. 如果中间跳出了就不是
    return i == len - 1;
  }
};

