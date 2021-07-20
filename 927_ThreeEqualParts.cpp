// 927. Three Equal Parts
/*
 * You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts
 * such that all of these parts represent the same binary value.

If it is possible, return any [i, j] with i + 1 < j, such that:

arr[0], arr[1], ..., arr[i] is the first part,
arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
All three parts have equal binary values.
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents.
For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

*/

// 思路: 首先每个划分出的部分其中的1的个数要相同. 其次, 最后一组的末尾可能有cnt个0, 因为是尾部出现的0
// 因此这些0都是有效位, 所以前面2组划分的结果, 它们的末尾也要包含cnt个0才可以.

class Solution {
public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0) return {-1, -1};  // 3的个数不能被3整除, 不可能划分成功
    if (sum == 0) return {0, (int)arr.size() - 1};  // 没有1, 因此随便划分都行

    int oneCnts = sum / 3;   // 1的个数要3等分

    // 记录下每组第一个1和最后一个1的位置
    vector<int> first(2, -1);
    vector<int> second(2, -1);
    vector<int> third(2, -1);

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 1) {
        if (cnt1 != oneCnts) {
          if (first[0] == -1) {
            first[0] = i;
          }
          cnt1++;
          if (cnt1 == oneCnts) {
            first[1] = i;
          }
        } else if (cnt2 != oneCnts) {
          if (second[0] == -1) {
            second[0] = i;
          }
          cnt2++;
          if (cnt2 == oneCnts) {
            second[1] = i;
          }
        } else {
          if (third[0] == -1) {
            third[0] = i;
          }
          cnt3++;
          if (cnt3 == oneCnts) {
            third[1] = i;
          }
        }
      }
    }

    // 计算最后一组尾部的0的个数
    int trailingZerosCnt = 0;
    for (int j = arr.size() - 1; j >= 0; j--) {
      if (arr[j] == 1) {
        break;
      } else {
        trailingZerosCnt++;
      }
    }

    // 因为是尾部出现的0, 因此这些0都是有效位
    // 所以前面2组的末尾都必须包含这么多个0
    first[1] += trailingZerosCnt;
    second[1] += trailingZerosCnt;
    third[1] += trailingZerosCnt;

    if (first[1] >= second[0] ||second[1] >= third[0]) return {-1, -1};

    // 逐个比较. 中间有任何不相同的情况表示2进制不相同
    int idx1 = first[0], idx2 = second[0], idx3= third[0];
    while (idx1 <= first[1] && idx2 <= second[1] && idx3 <= third[1]) {
      if (arr[idx1] != arr[idx2] || arr[idx1] != arr[idx3] || arr[idx2] != arr[idx3]) {
        return {-1, -1};
      }
      idx1++;
      idx2++;
      idx3++;
    }

    return {first[1], second[1] + 1};
  }
};
