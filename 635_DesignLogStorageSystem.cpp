// 635. Design Log Storage System
/*
 * You are given several logs, where each log contains a unique ID and timestamp.
 * Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59.
 * All domains are zero-padded decimal numbers.

Implement the LogSystem class:
    LogSystem() Initializes the LogSystem object.
    void put(int id, string timestamp) Stores the given log (id, timestamp) in your storage system.
    int[] retrieve(string start, string end, string granularity)
    Returns the IDs of the logs whose timestamps are within the range from start to end inclusive.
    start and end all have the same format as timestamp, and granularity means how precise the range should be
    (i.e. to the exact Day, Minute, etc.).
    For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", and granularity = "Day" means that we need to
    find the logs within the inclusive range from Jan. 1st 2017 to Jan. 2nd 2017, and the Hour, Minute, and Second for each log entry can be ignored.

Example 1:

Input
["LogSystem", "put", "put", "put", "retrieve", "retrieve"]
[[], [1, "2017:01:01:23:59:59"], [2, "2017:01:01:22:59:59"],
[3, "2016:01:01:00:00:00"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year"],
["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour"]]

Output
[null, null, null, null, [3, 2, 1], [2, 1]]

*/

// Solution:
// 使用平衡搜索二叉树保存log, key就是timestamp, value就是id
// 查询时可以使用二分查找, 找到start和end的边界, 范围内所有存在的id都加入结果中
//
class LogSystem {
public:
  LogSystem() {
    mp["Year"] = 4;
    mp["Month"] = 7;
    mp["Day"] = 10;
    mp["Hour"] = 13;
    mp["Minute"] = 16;
    mp["Second"] = 19;

    maxi = "2017:12:31:23:59:59";
    mini = "2000:01:01:00:00:00";
  }

  void put(int id, string timestamp) {
    hashtable.insert({timestamp, id});
  }

  vector<int> retrieve(string start, string end, string granularity) {
    int idx = mp.find(granularity)->second;
    string st = start.substr(0, idx) + mini.substr(idx);
    string en = end.substr(0, idx) + maxi.substr(idx);

    auto it_start = hashtable.lower_bound(st);   // binary search
    auto it_end   = hashtable.upper_bound(en);   // binary search
    vector<int> ans;
    for (auto it = it_start; it != it_end; it++) {
      ans.push_back(it->second);
    }
    return ans;
  }
private:
  multimap<string, int> hashtable;
  unordered_map<string, int> mp;
  string maxi;
  string mini;
};



