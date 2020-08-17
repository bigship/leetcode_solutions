// 976. Largest Perimeter Triangle
/*
 * Given an array A of positive lengths, return the largest perimeter of a triangle
 * with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

Example 1:

Input: [2,1,2]
Output: 5

Example 2:

Input: [1,2,1]
Output: 0

Example 3:

Input: [3,2,3,4]
Output: 10

Example 4:

Input: [3,6,2,3]
Output: 8

Note:
    3 <= A.length <= 10000
    1 <= A[i] <= 10^6
*/
class Solution {
public:
  int largestPerimeter(vector<int>& A) {
    std::sort(A.begin(), A.end(), std::greater<int>());
    for (int i = 0; i < A.size(); i++) {
      int j = i + 1;
      int k = A.size() - 1;
      while (j < k) {
        if (A[i] < A[j] + A[k]) return A[i] + A[j] + A[j+1];
        else k--;
      }
    }
    return 0;
  }
};


