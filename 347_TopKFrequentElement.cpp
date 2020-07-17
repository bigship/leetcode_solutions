// 347. Top K Frequent Element
/*
 * Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& val : nums) ++m[val];   // 先统计词频

        // 建一个大顶堆, 堆顶元素就是出现频率最高的数
        auto cmp = [&](int l, int r) { return m[l] < m[r]; };  // 大顶堆默认用less
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);

        for (auto& v : m)
            q.push(v.first);

        vector<int> ans;

        // 依次从堆顶取出前k个数, 即为解
        for (int i = 0; i < k; i++) {
            ans.push_back(q.top());
            q.pop();
        }

        return ans;
    }
};
