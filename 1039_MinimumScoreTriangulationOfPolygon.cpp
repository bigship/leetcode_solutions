// 1039. Minimum Score Triangulation of Polygon
/*
 * You have a convex n-sided polygon where each vertex has an integer value.
 * You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles.
For each triangle, the value of that triangle is the product of the values of its vertices,
and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.
*/
// Solution: dp[i][j] 表示多边形从第i个点到第j个点之间的所有三角形得分之和
// 注意如果start和end相邻, 那么从start到end只有一条边, 此时无法构成三角形. 那么此时dp[i][j] = 0
// 如果start和end不相邻, dp[i][j] = min(dp[start][k], dp[k][end], A[start] * A[k] * A[end])  其中 start < k < end
class Solution {
public:
  int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return getScore(values, dp, 0, n - 1);
  }
private:
  int getScore(const vector<int>& A, vector<vector<int>>& dp, int start, int end) {
    if (start >= end - 1) return 0;  // 只有一条边, 无法构成三角形
    if (dp[start][end] > 0) return dp[start][end];
    int score = INT_MAX;
    for (int k = start + 1; k <= end - 1; k++) {
      score = min(score, getScore(A, dp, start, k) + getScore(A, dp, k, end) + A[start] * A[k] * A[end]);
    }
    dp[start][end] = score;
    return score;
  }
};
