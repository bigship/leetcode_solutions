/*
 Given a sorted list of positive numbers, find the smallest positive number
 that cannot be a sum of any subset in the list.
 
 Example: [1, 2, 3, 8, 9, 10]
 Output: 7
 */

int findSmallest(vector<int>& nums) {
    int candidate = 1;   // 1 is potentially the smallest, we start from 1
    for (int i = 0; i < nums.size() && nums[i] <= candidate; i++) {
        candidate += nums[i];
    }
    return candidate;
}
