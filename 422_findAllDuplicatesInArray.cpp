// 422. Find all duplicates in an array
/*
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.

Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

// using unordered_map O(n) space
vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> m;
    vector<int> ans;
    for (auto& v : nums) ++m[v];
    for (auto it = m.begin(); m != m.end(); ++it) {
        if (it->second == 2) ans.push_back(it->first);
    }
    return ans;
}

// without extra space
// tricky !!  1 ≤ a[i] ≤ n (n = size of array) is the key point
vector<int> findDuplicates_noExtraSpace(vector<int>& nums) {
    vector<int> ans;
    for (auto& num : nums) {
        int index = abs(num) - 1;
        if (nums[index] < 0)
            ans.push_back(index + 1);
        nums[index] = -nums[index];
    }
    return ans;
}

