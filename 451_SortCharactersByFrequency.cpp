// 451. Sort Characters By Frequency
/*
 * Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
  // 直接排序 Time - O(nlogn)
  string frequencySort(string s) {
    unordered_map<char, int> m;
    for (auto& ch : s) ++m[ch];
    auto cmp = [&](char c1, char c2) {
      if (m[c1] == m[c2]) return c1 < c2;
      return m[c1] > m[c2];
    }
    std::sort(s.begin(), s.end(), cmp);
    return s;
  }

  // 建堆, 提供一个自定义的比较函数, 类似排序的方法
  // 不断把字符push到堆中, 再不断pop出来同时构建解
  // Time - O(nlogn)
  string frequencySort(string s) {
    unordered_map<char, int> m;
    for (auto& ch : s) ++m[ch];

    auto cmp = [&](char c1, char c2) {
      if (m[c1] == m[c2]) return c1 < c2;
      return m[c1] < m[c2];  // max heap
    };
    std::priority_queue<char, std::vector<char>, decltype(cmp)> q(cmp);
    for (auto& ch : s) q.push(ch);

    string ans = "";
    while (!q.empty()) {
      ans += q.top();
      q.pop();
    }
    return ans;
  }

  // 利用map的key是有序的, 插入map的复杂度为logn
  // Time - O(n)
  string frequencySort(string s) {
    unordered_map<char, int> m;
    for (auto& ch : s) ++m[ch];

    // map通常为红黑树, 插入节点只需要logn时间
    map<int, string> sm;
    for (auto& item : m) {
      int ch = item.first;
      int cnt = item.second;
      m[cnt] += string(cnt, ch);  // 可能多个字符出现的次数相同, 因此要累加
    }

    // 倒序遍历map, 同时构建解
    string ans = "";
    for (auto it = sm.rbegin(); it != sm.rend(); it++) {
      ans += it->second;
    }
    return ans;
  }
};
