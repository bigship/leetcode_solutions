// 915. Partition Array into Disjoint Intervals
/*
 * Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.



Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

Note:

2 <= nums.length <= 30000
0 <= nums[i] <= 10^6
It is guaranteed there is at least one way to partition nums as described.
*/

class Solution {
public:
  Solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }
  // [5,0,3,8,6]
  // 思路: 维护两个堆. 左侧为大顶堆, 右侧为小顶堆
  // 只要大顶堆的堆顶比小顶堆的堆顶要小, 则表示左侧的元素都比右侧元素小, 划分完成
  // 每个元素最多被加入堆2次, 弹出堆1次. O(nlogn)
  int partitionDisjoint(vector<int>& nums) {
    std::priority_queue<int, vector<int>> maxHeap;   // left
    std::priority_queue<int, vector<int>, std::greater<int>> minHeap; // right
    std::unordered_map<int, int> idxmap;
    std::vector<int> maxHeapIdx;
    for (int i = 0; i < nums.size(); i++) {
      idxmap[nums[i]] = i;
    }

    maxHeap.push(nums[0]);
    maxHeapIdx.push_back(0);
    for (int i = nums.size() - 1; i > 0; i--) {
      minHeap.push(nums[i]);
    }

    while (maxHeap.top() > minHeap.top()) {
      int v = minHeap.top();
      minHeap.pop();
      int idx = idxmap[v];

      // maxHeap要一直加入数据直到idx(包括idx)
      for (int i = maxHeapIdx.back() + 1; i <= idx; i++) {
        maxHeapIdx.push_back(i);
        maxHeap.push(nums[i]);
      }
    }
    return maxHeap.size();
  }

  // 解法2: 其实不需要用堆来维护最大和最小值
  // 用数组即可. maxElement[i] = std::max(maxElement[i - 1], nums[i])
  // 同理可维护minElement
  // O(n)
  int partitionDisjoint(vector<int>& nums) {
    const int n = nums.size();
    vector<int> maxleft(n, 0);
    vector<int> minright(n, 0);

    int m = nums[0];
    for (int i = 0; i < n; i++) {
      m = std::max(m, nums[i]);
      maxleft[i] = m;
    }

    m = nums[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      m = std::min(m, nums[i]);
      minright[i] = m;
    }

    for (int i = 1; i < n; i++) {
      if (maxleft[i - 1] <= minright[i]) {
        return i;
      }
    }

    return -1;
  }
};
