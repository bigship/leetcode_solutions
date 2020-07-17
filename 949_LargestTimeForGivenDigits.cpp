// 949. Largest Time for Given Digits
/*
 * Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00,
a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.


Example 1:

Input: [1,2,3,4]
Output: "23:41"

Example 2:

Input: [5,5,5,5]
Output: ""

Note:

    A.length == 4
    0 <= A[i] <= 9

*/

class Solution {
public:
    // Brute force. 因为每个数字取一次不能重复, 下标之和就是 0 + 1 + 2 + 3 = 6
    string largestTimeForDigits(vector<int>& A) {
        int ans = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    for (int k = 0; k < 4; k++) {
                        if (i != k && j != k) {
                            int l = 6 - i - k - j;

                            int hours = 10 * A[i] + A[j];
                            int mins = 10 * A[k] + A[l];
                            if (hours < 24 && mins < 60) {
                                ans = std::max(ans, hours * 60 + mins);
                            }
                        }
                    }
                }
            }
        }
        if (ans >= 0) {
            string h = to_string(ans / 60);
            if (h.size() == 1) h = "0" + h;

            string m = to_string(ans % 60);
            if (m.size() == 1) m = "0" + m;

            return h + ":" + m;
        }

        return "";
    }
};


