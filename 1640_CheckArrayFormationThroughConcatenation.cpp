// 1640. Check Array Formation Through Concatenation
/*
 * You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct.
 * Your goal is to form arr by concatenating the arrays in pieces in any order.
 * However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

Example 1:

Input: arr = [85], pieces = [[85]]
Output: true

Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]

Example 3:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].

Example 4:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]

Example 5:

Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false

Constraints:
    1 <= pieces.length <= arr.length <= 100
    sum(pieces[i].length) == arr.length
    1 <= pieces[i].length <= arr.length
    1 <= arr[i], pieces[i][j] <= 100
    The integers in arr are distinct.
    The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).
*/

// Brute Force. TLE !!
// 根据pieces数组产生所有可能的连接, 判断是否有一组连接可以与数组arr相同
// 利用回溯法产生pieces数组的所有排列
class Solution {
public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> used(pieces.size(), 0);
    bool ans = false;
    vector<int> cur;
    backtrack(pieces, used, ans, arr, cur);
    return ans;
  }
private:
  vector<int> cancateVector(vector<int>& arr, vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      arr.push_back(nums[i]);
    }
    return arr;
  }

  void removeVector(vector<int>& arr, vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
      arr.pop_back();
  }

  void backtrack(vector<vector<int>>& pieces, vector<int>& used, bool& ans, vector<int>& arr,
                vector<int>& cur) {
    if (cur.size() > arr.size())
      return;
    if (cur == arr) {
      ans = true;
      return ;
    }
    for (int i = 0; i < pieces.size(); i++) {
      if (used[i]) continue;
      used[i] = 1;
      cur = cancateVector(cur, pieces[i]);
      backtrack(pieces, used, ans, arr, cur);
      removeVector(cur, pieces[i]);
      used[i] = 0;
    }
  }
};

// Time: O(N^2), Space: O(1)
class Solution2 {
public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    for (int i = 0; i < piece.size(); i++) {
      if (!isSubArray(arr, piece[i]))
        return false;
    }
    return true;
  }
private:
  bool isSubArray(vector<int>& arr, vector<int>& piece) {
    int first = piece[0];
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == first) {
        int j = 0;
        while (j < piece.size() && i < arr.size()) {
          if (arr[i++] != piece[j++])
            return false;
        }
        return j == piece.size();
      }
    }
    return false;
  }
};

// Time: O(N), Space: O(N)
class Solution3 {
public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, vector<int> *> map;
    for (int i = 0; i < pieces.size(); i++) {
      int firstval = pieces[i][0];
      map[firstval] = &pieces[i];
    }

    int idx = 0;
    while (idx < arr.size()) {
      int val = arr[idx];
      if (map.find(val) == map.end()) return false;
      auto it = map[val];
      int k = 0;
      while (k < (*it).size()) {
        if (arr[idx++] != (*it)[k++])
          return false;
      }
    }
    return true;
  }
};

