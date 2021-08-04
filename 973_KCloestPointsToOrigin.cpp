// 973. K closest Points to Origin
/*
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)

Note:
    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000
*/

class Solution {
public:
  // Sorting - O(nlog(n))
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    auto cmp = [&](vector<int>&left, vector<int>& right) {
      return static_cast<int>(pow(left[0], 2) + pow(left[1], 2)) <
          static_cast<int>(pow(right[0], 2) + pow(right[1], 2));
    }
    std::sort(points.begin(), points.end(), cmp);
    vector<vector<int>> ans;
    for (int i = 0; i < K; i++) {
      ans.push_back(points[i]);
    }
    return ans;
  }

  // Heap - O(nlogk)

  // quick select - O(n) average
  // 我们可以利用快速选择在O(n)的时间内找到第k小的距离, 然后再遍历一次距离数组
  // 把所有小于等于第k小距离的点加入到答案中即可
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // 需要先构造一个距离数组
    for (int i = 0; i < points.size(); i++) {
      long long d = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
      arr.push_back({d, i});
    }

    vector<vector<int>> rets;
    // 第k小的值, 其下标在排好序的数组中应该是k - 1
    long long kthdist = quickSelect(0, arr.size() - 1, k - 1);   // quick select average O(n)
    for (auto x : arr) {
      if (x.first <= kthdist) {
        rets.push_back(points[x.second]);
      }
    }
    return rets;
  }
private:
  vector<pair<long long, int>> arr;  // {distance, idx}

  long long quickSelect(int start, int end, int target_idx) {
    int i = start, r = end - 1, pivot = arr[end].first;
    for (int j = start; j <= r; j++) {
      if (arr[j].first <= pivot) {
        std::swap(arr[i], arr[j]);
        i++;
      }
    }
    std::swap(arr[i], arr[end]);
    if (i == target_idx) {
      return arr[i].first;
    } else if (i < target_idx) {
      return quickSelect(i + 1, end, target_idx);
    } else {
      return quickSelect(start, i - 1, target_idx);
    }
  }
};
