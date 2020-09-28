// 977. Squares of a Sorted Array
/*
 * Given an array of integers A sorted in non-decreasing order,
 * return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Note:

    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A is sorted in non-decreasing order.
*/

class Solution {
public:
  // Solution: sort. Time: O(nlog(n))
  vector<int> sortedSquares(vector<int>& A) {
    std::transform(A.begin(), A.end(), A.begin(), [&](int n) -> int {
      return n*n;
    });
    std::sort(A.begin(), A.end());
    return A;
  }

  // Solution: two pointers
  // 负数的平方是降序排列的, 正数的平方是升序排列的
  // 维护两个指针分别指向负数的最后一个以及正数的第一个
  // Time: O(N)
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> ans;
    int i = 0, j = 0;
    while (j < A.size() && A[j] < 0) {
      j++;
    }
    i = j - 1;

    while (i >= 0 && j <= A.size() - 1) {
      if (A[i]*A[i] < A[j]*A[j]) {
        ans.push_back(A[i]*A[i]);
        i--;
      } else {
        ans.push_back(A[j]*A[j]);
        j++;
      }
    }

    while (i >= 0) {
      ans.push_back(A[i]*A[i]);
      i--;
    }

    while (j <= A.size() - 1) {
      ans.push_back(A[j]*A[j]);
      j++;
    }
    return ans;
  }
};

