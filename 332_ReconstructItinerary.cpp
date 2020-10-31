// 332. Reconstruct Itinerary
/*
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
 * reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK.
 * Thus, the itinerary must begin with JFK.

Note:

    If there are multiple valid itineraries, you should return the itinerary that has
    the smallest lexical order when read as a single string. For example,
    the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
    One must use all the tickets once and only once.

Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/
class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    route_.clear();
    trips_.clear();

    for (const auto& ticket : tickets) {
      trips_[ticket[0]].push_back(ticket[1]);
    }

    for (auto& item : trips_) {
      auto& dests = item.second;
      std::sort(dests.begin(), dests.end());   // 目的地按字母排序
    }

    const string kStart = "JFK";   // 规定JFK开始
    visit(kStart);
    return vector<string>(route_.crbegin(), route_.crend());  // 要逆序, 因为是后续遍历加进去的
  }
private:
  unordered_map<string, deque<string>> trips_;
  vector<string> route_;

  void visit(const string& src) {
    auto& dests = trips_[src];
    while (!dests.empty()) {
      const string dest = dests.front();  // 已经排序过了, 从最小的开始遍历
      dests.pop_front();   // 要把这条边删除掉, 下次回来的时候就不用再走这条边了
      visit(dest);         // 递归, 继续从下一个位置开始遍历
    }
    route_.push_back(src); // 后续遍历, 处理完了所有的子节点再把src添加进去
  }
};



