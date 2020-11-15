// 246. Strobogrammatic Number
/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
   Write a function to determine if a number is strobogrammatic.
   The number is represented as a string.

Example 1:

Input: num = "69"
Output: true

Example 2:

Input: num = "88"
Output: true

Example 3:

Input: num = "962"
Output: false

Example 4:

Input: num = "1"
Output: true
*/

class Solution {
public:
  // 先排除2,3,4,5,7这些数字, 如果包含则一定为false
  // 倒序构建字符串, 如果是6则变成9, 9则变成6
  // 最后看reversed == num
  bool isStrobogrammatic(string num) {
    vector<char> filter = {'2', '3', '4', '5', '7'};
    for (int i = 0; i < filter.size(); i++) {
      if (num.find(filter[i]) != string::npos) {
        return false;
      }
    }

    string reversed;
    for (int i = num.length() - 1; i >= 0; i--) {
      if (num[i] == '6') {
        reversed = reversed + "9";
      } else if (num[i] == '9') {
        reversed = reversed + "6";
      } else {
        reversed = reversed + string(1, num[i]);
      }
    }
    return reversed == num;
  }
};


