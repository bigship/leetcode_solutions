// 846. Hand of Straights
/*
 * Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
Return true if and only if she can.

Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

Constraints:
    1 <= hand.length <= 10000
    0 <= hand[i] <= 10^9
    1 <= W <= hand.length
*/
// 把牌分成W份, 每份W张牌
class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int W) {
    const int len = hand.size();

    // W不能被牌的总数整除, 一定不满足条件
    if (len % W != 0)
      return false;

    // 统计牌出现的次数, 使用平衡二叉树
    std::map<int, int> cntmap;
    for (auto& card : hand) {
      cntmap[card]++;
    }

    // 从最小的牌开始算. 看是否能凑出W张牌, 每张牌顺序加1
    // 如果这个过程无法满足, 表示无法凑出返回false
    // 每次使用过的牌把它出现的次数减去1, 如果次数为0就从cntmap中删除这张牌
    // 表示这张牌不会再被使用到了
    while (!cntmap.empty()) {
      auto it = cntmap.begin();
      int start = it->first;
      for (int i = 0; i < W; i++) {
        if (cntmap.find(start + i) == cntmap.end())
          return false;
        else {
          cntmap[start + i]--;
          if (cntmap[start + i] == 0) {
            cntmap.erase(start + i);
          }
        }
      }
    }

    return true;
  }
};


