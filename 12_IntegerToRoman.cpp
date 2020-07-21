// 12. Integer to Roman
/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"

Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    // Too complex, error pron, bad implementation
    string intToRoman(int num) {
        string ans = "";
        deque<int> q;
        while (num) {
            q.push_front(num % 10);
            num /= 10;
        }
        int sz = q.size();
        while (sz < 4) {
            q.push_front(0);
            sz++;
        }

        for (int i = 0; i < q.size(); i++) {
            if (i == 0 && q[i] != 0) {   // thousand
                while (q[i] > 0) {
                    ans += "M";
                    q[i]--;
                }
            }

            if (i == 1 && q[i] != 0) {   // hundred
                if (q[i] == 5) ans = ans + "D";
                if (q[i] == 4) ans = ans + "CD";
                if (q[i] == 9) ans = ans + "CM";
                if (q[i] > 5 && q[i] < 9) {
                    ans = ans + "D";
                    while (q[i] - 5 > 0) {
                        ans = ans + "C";
                        q[i]--;
                    }
                } else if (q[i] > 0 && q[i] < 4) {
                    while (q[i] > 0) {
                        ans = ans + "C";
                        q[i]--;
                    }
                }
            }

            if (i == 2 && q[i] != 0) {  // ten
                if (q[i] == 5) ans = ans + "L";
                if (q[i] == 4) ans = ans + "XL";
                if (q[i] == 9) ans = ans + "XC";
                if (q[i] > 5 && q[i] < 9) {
                    ans = ans + "L";
                    while (q[i] - 5 > 0) {
                        ans = ans + "X";
                        q[i]--;
                    }
                } else if (q[i] > 0 && q[i] < 4) {
                    ans = ans + "X";
                    while (q[i] > 0) {
                        ans = ans + "X";
                        q[i]--;
                    }
                }
            }

            if (i == 3 && q[i] != 0) {
                if (q[i] == 5) ans = ans + "V";
                if (q[i] == 9) ans = ans + "IX";
                if (q[i] == 4) ans = ans + "IV";
                if (q[i] > 5 && q[i] < 9) {
                    ans = ans + "V";
                    while (q[i] - 5 > 0) {
                        ans = ans + "I";
                        q[i]--;
                    }
                } else if (q[i] > 0 && q[i] < 4) {
                    while (q[i] > 0) {
                        ans = ans + "I";
                        q[i]--;

                    }
                }
            }
        }
        return ans;
    }

    // Recursion, much more elegant
    string intToRoman(int num) {
        if (num >= 1000) return ("M" + intToRoman(num - 1000));
        if (num >= 900) return ("CM" + intToRoman(num - 900));
        if (num >= 500) return ("D" + intToRoman(num - 500));
        if (num >= 400) return ("CD" + intToRoman(num - 400));
        if (num >= 100) return ("C" + intToRoman(num - 100));
        if (num >= 90) return ("XC" + intToRoman(num - 90));
        if (num >= 50) return ("L" + intToRoman(num - 50));
        if (num >= 40) return ("XL" + intToRoman(num - 40));
        if (num >= 10) return ("X" + intToRoman(num - 10));
        if (num == 9) return "IX";
        if (num == 8) return "VIII";
        if (num == 7) return "VII";
        if (num == 6) return "VI";
        if (num == 5) return "V";
        if (num == 4) return "IV";
        if (num == 3) return "III";
        if (num == 2) return "II";
        if (num == 1) return "I";
        if (num == 0) return "";
        return "";
};






