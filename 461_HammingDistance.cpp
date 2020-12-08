// 461. Hamming Distance
/*
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
  // 32位整数, 算x^y的结果中有多少个1即可
  int hammingDistance(int x, int y) {
    return std::bitset<32>(x^y).count();
  }

  int hammingDistance_manually(int x, int y) {
    int mask = 0x01;
    int distance = 0;
    for (int i = 0; i < 32; i++) {
      if ((x & mask) ^ (y & mask) == 1) {
        distance++;
      }
      x = x >> 1;
      y = y >> 1;
    }
    return distance;
  }
};

