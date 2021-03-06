// 1395. Count Number of Teams
/*
 * There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4

Constraints:

    n == rating.length
    1 <= n <= 200
    1 <= rating[i] <= 10^5
*/
class Solution {
public:
  int numTeams(vector<int>& rating) {
    int ans = 0;
    const int n = rating.size();
    int i = 0, j = 0, k = 0;
    for (i = 0; i < len; i++) {
      int l = 0, r = 0;

      // 以i为基准, 看i的左边有多少个数小于它
      for (j = 0; j < i; j++) {
        if (rating[j] < rating[i]) l++;
      }

      // 以i为基准, 看i的右边有多少个数大于它
      for (k = i + 1; k < n; k++) {
        if (rating[i] < rating[k]) r++;
      }

      // 根据乘法原理, 这样的3元数的个数就是l * r
      // 同样道理, 可以得到递减的3元数. 把它们加起来
      ans += (l * r) + (i - l) * (n - i - 1 - r);
    }
    return ans;
  }
};

