// 1291. Sequential Digits
/*
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
   Return a sorted list of all the integers in the range [low, high]
   inclusive that have sequential digits.

Example 1:

Input: low = 100, high = 300
Output: [123,234]

Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:

    10 <= low <= high <= 10^9
*/

class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    // 产生所有的sequential数并存入set, set是有序序列可使用二分
    set<int> sequential;
    int i = 1, j = 1, seq = 0;
    while (i < 10) {
      seq = seq * 10 + j;
      sequential.insert(seq);
      if (j == 9) {
        i++;
        seq = 0;
        j = i;
        continue;
      }
      j++;
    }

    // l -> 第一个比low - 1 大的
    auto l = upper_bound(sequential.begin(), sequential.end(), low - 1);
    // r -> 第一个比high + 1 小的
    auto r = lower_bound(sequential.begin(), sequential.end(), high + 1);
    return vector(l, r);
  }

  // 直接打表
  vector<int> sequentialDigits_table(int low, int high) {
    vector<vector<int>> table = {
      {12, 23, 34, 45, 56, 67, 78, 89},
      {123,234,345,456,567,678,789},
      {1234,2345,3456,4567,5678,6789},
      {12345,23456,34567,45678,56789},
      {123456,234567,345678,456789},
      {1234567,2345678,3456789},
      {12345678,23456789},
      {123456789}
    };
    vector<int> ans;
    for (auto& vec : table) {
      for (auto& val : vec) {
        if (val >= low && val <= high)
          ans.push_back(val);
      }
    }
    return ans;
  }
};


