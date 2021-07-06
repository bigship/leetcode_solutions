// 1338. Reduce Array Size to the Half
/*
 * Given an array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.


Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2]
which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5]
which has size greater than half of the size of the old array.

Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
*/

class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> cntmap;
    for (auto v : arr) {
      cntmap[v]++;
    }
    std::sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
      if (cntmap[a] == cntmap[b]) {
       return a < b;
      }
      return cntmap[a] > cntmap[b];
    });

    int ans = 0;
    int cnt = 0;
    int idx = 0;
    while (idx < arr.size()) {
      ans += 1;
      cnt += cntmap[arr[idx]];
      if (cnt >= arr.size() / 2) {
        return ans;
      }
      idx += cntmap[arr[idx]];
    }
    return ans;
  }
};
