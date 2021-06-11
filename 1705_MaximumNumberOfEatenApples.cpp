// 1705. Maximum Number of Eaten Apples
/*
 * There is a special kind of apple tree that grows apples every day for n days. On the ith day,
 * the tree grows apples[i] apples that will rot after days[i] days,
 * that is on day i + days[i] the apples will be rotten and cannot be eaten.
 * On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.

You decided to eat at most one apple a day (to keep the doctors away).
Note that you can keep eating after the first n days.
Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.
*/

// 贪心. 尽可能早的吃掉过期时间短的苹果
class Solution {
public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    int res = 0, size = apples.size(), day = 0;
    auto cmp = [](const auto& p1, const auto& p2) {
      return p1.first > p2.first;
    };

    // first: rotten_day, second: rotten_num
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);   // minHeap

    while (day < size || !heap.empty()) {
      if (day < size && apples[day] > 0) {
        heap.push({day + days[day], apples[day]});
      }

      // already outdated. pop out
      while (!heap.empty() && heap.top().first <= day) {
        heap.pop();
      }

      if (!heap.empty()) {
        auto top = heap.top();
        heap.pop();
        --top.second;  // eat one
        ++res;

        // If we still have some left, push to pq again
        if (top.second > 0) {
          heap.push(top);
        }
      }
      ++day;
    }

    return res;
  }
};



