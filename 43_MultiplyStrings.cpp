// 43. Multiply Strings
/*
 * Given two non-negative integers num1 and num2 represented as strings, 
 * return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        const int l1 = num1.length();
        const int l2 = num2.length();
        deque<int> q;
        int carry = 0;
        int cnt = 0;
        string ans = "0";
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int cur = n1 * n2 + carry;
                if (cur >= 10) {
                    carry = cur / 10;
                    cur = cur % 10;
                } else {
                    carry = 0;
                }
                q.push_front(cur);
            }
            if (carry)
                q.push_front(carry);
            if (cnt > 0) {
                int tmp = cnt;
                while (tmp) {
                    q.push_back(0);
                    tmp--;
                }
            }
            cnt++;
            string ret;
            for (auto it = q.begin(); it != q.end(); it++) {
                ret += to_string(*it);
            }
            ans = stringAdd(ret, ans);
            q.clear();
            carry = 0;
        }
        return ans;
    }
private:
    string stringAdd(string s1, string s2) {
        int carry = 0;
        if (s1.length() < s2.length()) {
            std::swap(s1, s2);
        }
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        deque<int> q;
        while (i >= 0 && j >= 0) {
            int n1 = s1[i--] - '0';
            int n2 = s2[j--] - '0';
            int cur = n1 + n2 + carry;
            if (cur >= 10) {
                carry = 1;
                cur -= 10;
            } else {
                carry = 0;
            }
            q.push_front(cur + '0');
        }
        while (i >= 0) {
            int ni = s1[i--] - '0';
            int cur = ni + carry;
            if (cur >= 10) {
                carry = 1;
                cur -= 10;
            } else {
                carry = 0;
            }
            q.push_front(cur + '0');    
        }
        if (carry) {
            q.push_front(carry + '0');
        }
        return string(q.begin(), q.end());
    }
};
