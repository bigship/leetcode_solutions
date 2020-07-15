// 905. Sort Array By Parity
/*
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.

   You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

    1 <= A.length <= 5000
    0 <= A[i] <= 5000
*/

class Solution {
public:
    // In place swap, Time - O(n), Space - O(1)
    vector<int> sortArrayByParity_InPlace(vector<int>& A) {
        int n = A.size();
        for (int i = 0, int j = i + 1; i < n && j < n; ) {
            if (A[i] % 2 == 1 && A[j] % 2 == 0) {
                std::swap(A[i], A[j]);
                ++i;
                ++j;
            } else if (A[i] % 2 == 1 && A[j] % 2 == 1) {
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return A;
    }

    // Time - O(n), Space - O(n)
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        for (auto& val : A) {
            if (val % 2 == 0) even.push_back(val);
            else odd.push_back(val);
        }
        int n1 = even.size();
        int n2 = odd.size();
        for (int i = 0; i < n1; ++i)
            A[i] = even[i];
        for (int j = n1; j < n1 + n2; ++j)
            A[j] = odd[j - n1];
        return A;
    }
};


