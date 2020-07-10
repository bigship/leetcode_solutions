// 66. Plus One
/*
 * Given a non-empty array of digits representing a non-negative integer,
 * increment one to the integer.

The digits are stored such that the most significant digit is at the head of the
list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int cur = 0, carry = 0;
        deque<int> q;
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) cur = digits[i] + 1;
            else cur = digits[i] + carry;
            if (cur >= 10) {
                q.push_front(cur%10);
                carry = 1;
            } else {
                q.push_front(cur);
                carry = 0;
            }
        }

        // If we still have a carry
        if (carry) q.push_front(carry);
        return vector<int>(q.begin(), q.end());
    }
};


