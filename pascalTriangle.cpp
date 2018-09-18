// 118. Pascal's Triangle

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

// First fill all sub array with 1
// Then, iterate all sub array, modify value with the formula ans[i][j] = ans[i-1][j-1] + ans[i-1][j]

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return vector<vector<int>>{{1}};
    if (numRows == 2) return vector<vector<int>>{{1}, {1, 1}};
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
      vector<int> sub(i+1, 1);
      ans.push_back(sub);
    }
    
    for (int i = 2; i < numRows; i++) {
      for (int j = 1; j <= ans[i].size()-2; j++) {
        ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
      }
    }
    return ans;
  }
};
