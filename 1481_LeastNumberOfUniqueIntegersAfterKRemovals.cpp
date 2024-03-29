// 1481. Least Number of Unique Integers after K Removals
/*
 * Given an array of integers arr and an integer k.
 * Find the least number of unique integers after removing exactly k elements.

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
*/

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    std::unordered_map<int, int> m;
		for (int i = 0; i < arr.size(); i++){
			m[arr[i]]++;
		}
		std::priority_queue<int, vector<int>, std::greater<int>> pq;  // min heap
      for (auto i : m) {
			pq.push(i.second);
		}

		while (k > 0) {
			k -= pq.top();
			if (k >= 0) {
				pq.pop();
			}
		}

		return pq.size();
  }
};
