// 477. Total Hamming Distance
/*
 * The Hamming distance between two integers is the number of positions at which
 * the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:

Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Note:

    Elements of the given array are in the range of 0 to 10^9
    Length of the array will not exceed 10^4.
*/

class Solution {
public:
  // 题目限定为32位整数
  // 要产生汉明距离只有对应的位不相同才可以
  // 于是针对每一位将数组分成两个部分, 此位是1 以及此位是0
  // 计算每一位上1的个数, 则0的个数为nums.size() - 1的个数
  // 由于是求每一对数之间的汉明距离, 因此就是1的个数乘以0的个数
  // 从0-31对每一位重复上述过程, 累加结果即可
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    unsigned int mask = 1;
    for (int i = 0; i < 32; i++) {
      int count = 0;
      for (auto& num : nums) {
        if (num & mask) count++;
      }
      ans += count * (nums.size() - count);
      mask <<= 1;
    }
    return ans;
  }

  // Brute force的做法, Time - O(n^2)  TLE !!
  // 数据规模太大, 会超时
  // 思路是对每一对数求异或, 则这一对数的汉明距离就是异或结果的二进制位为1的个数
  // 枚举每一对数求解累加即可
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        ans += countBitOne(nums[i], nums[j]);
      }
    }
    return ans;
  }

private:
  int countBitOne(int n1, int n2) {
    int cnt = 0;
    int n = n1 ^ n2;
    while (n) {
      cnt++;
      n = n & (n - 1);
    }
    return cnt;
  }
};

