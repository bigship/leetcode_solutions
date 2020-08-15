// 1090. Largest Values From Labels
/*
 * We have a set of items: the i-th item has value values[i] and label labels[i].
   Then, we choose a subset S of these items, such that:

  |S| <= num_wanted
  For every label L, the number of items in S with label L is <= use_limit.

Return the largest possible sum of the subset S.

Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.

Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.

Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.

Example 4:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.

Note:

    1 <= values.length == labels.length <= 20000
    0 <= values[i], labels[i] <= 20000
    1 <= num_wanted, use_limit <= values.length
*/

class Solution {
public:
  // Solution 1: use multimap, insert time O(lgN), key is sorted
  // Iterate multimap in reverse order, we get the largest value at the beginning
  int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
    multimap<int, int> multi;   // same value may have different labels, so use multimap
    unordered_map<int, int> n;  // count label used times
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < values.size(); i++) {
      multi.insert({values[i], labels[i]});
    }
    for (auto it = multi.rbegin(); it != multi.rend() && cnt < num_wanted; it++) {
      if (n[it->second]++ < use_limit) {
        ans += it->first;
        cnt++;
      }
    }
    return ans;
  }

  // Solution 2: Sorting by values
  int largestValsFromLabels_sort(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < values.size(); i++) {
      vec.push_back({labels[i], values[i]});
    }
    std::sort(vec.begin(), vec.end(), [&](auto v1, auto v2) {
      return v1.second > v2.second;
    });

    int cnt = 0;
    int ans = 0;
    unordered_map<int, int> m;  // count label used times
    auto it = vec.begin();
    while (cnt < num_wanted && it != vec.end()) {
      if (m[(*it).first]++ < use_limit) {
        ans += (*it).second;
        cnt++;
      }
      it++;
    }
    return ans;
  }
};


