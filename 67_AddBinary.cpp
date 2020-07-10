// 67. Add Binary
/*
 * Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"



Constraints:

    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        if (a.size() < b.size()) std::swap(a, b);

        int l1 = a.size();
        int l2 = b.size();
        int i = l1 - 1;
        int j = l2 - 1;
        int carry = 0;

        while (i >= 0 && j >= 0) {
            int b_ = b[j--] - '0';
            int a_ = a[i--] - '0';
            if (a_ + b_ + carry == 2) {
                ans = '0' + ans;
                carry = 1;
            } else if (a_ + b_ + carry == 0) {
                ans = '0' + ans;
                carry = 0;
            } else if (a_ + b_ + carry == 1) {
                ans = '1' + ans;
                carry = 0;
            } else if (a_ + b_ + carry == 3) {
                ans = '1' + ans;
                carry = 1;
            }
        }
        while (i >= 0) {
            int a_ = a[i--] - '0';
            if (carry + a_ == 0)
                ans = '0' + ans;
            if (carry + a_ == 1) {
                ans = '1' + ans;
                carry = 0;
            }
            if (carry + a_ == 2) {
                ans = '0' + ans;
                carry = 1;
            }
        }
        if (carry) ans = '1' + ans;
        return ans;
    }
};

