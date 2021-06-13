// 767. Reorganize String
/*
 * Given a string S, check if the letters can be rearranged so that two characters
 * that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"

Example 2:

Input: S = "aaab"
Output: ""

Note:

    S will consist of lowercase letters and have length in range [1, 500].
*/

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 先统计字符出现的频率
// 如果出现最多的字符次数大于字符串长度 + 1 除以2表示无法满足返回""
// 从频率最高的字符开始, 依次写入偶数位置 0,2,4,6,8 ...
// 遍历整个hashmap, 写入其他的字符. 顺着偶数位继续写入, 如果发现索引位置超过了
// 字符串长度, 则折回写入位置1, 然后依次写入奇数位置 这样就可以保证相邻字符不会
// 重复

class Solution {
public:
  string reorganizeString(string S) {
    if (S.length() == 0) return "";
    unordered_map<char, int> m;
    for (auto& ch : S) {
      m[ch]++;
    }

    int maxfreq = 0, letter = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (maxfreq < it->second) {
        maxfreq = it->second;
        letter = it->first;
      }
    }

    if (maxfreq > (S.length() + 1) / 2)
      return "";

    string ans(S.length(), '.');
    // 先写入频率最高的字符, 从偶数位置依次写入
    int idx = 0;
    while (m[letter] > 0) {
      ans[idx] = letter;
      idx += 2;
      m[letter]--;
    }

    // 遍历hashmap, 写入其他的字符. 依旧是顺着之前的偶数位置写入
    // 如果发现索引超过了字符串长度, 就折回从奇数位置继续写
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second > 0) {
        while (it->second) {
          if (idx >= ans.length()) {
            idx = 1;
          }
          ans[idx] = it->first;
          it->second--;
          idx += 2;
        }
      }
    }

    return ans;
  }
};


// Greedy. priority_queue
// 统计字母出现的次数. 按字母出现的次数为顺序构建大顶堆
// 每次优先取频率最高的两个字母交替组合. 如果发现出现相邻两个字母一样, 表示无法组成
class Solution {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> cntmap;
    for (auto ch : s) {
      cntmap[ch]++;
    }

    auto cmp = [&](const pair<char, int>& a, const pair<char, int>& b) {
      if (a.second == b.second) {
        return a.first > b.first;
      }
      return a.second < b.second;
    };
    std::priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxHeap(cmp);
    for (auto it = cntmap.begin(); it != cntmap.end(); it++) {
      maxHeap.push({it->first, it->second});
    }

    string ans;
    while (!maxHeap.empty()) {
      auto t = maxHeap.top();
      maxHeap.pop();
      if (!ans.empty() && ans.back() == t.first) {
        return "";
      }
      ans += t.first;
      t.second--;

      if (!maxHeap.empty()) {
        auto u = maxHeap.top();
        maxHeap.pop();
        ans += u.first;
        u.second--;

        if (u.second > 0) {
          maxHeap.push(u);
        }
      }
      if (t.second > 0) {
        maxHeap.push(t);
      }
    }

    return ans;
  }
};



int main() {
  //string input = "tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao";
  string input = "aaaabca";
  cout << Solution().reorganizeString(input) << endl;
  return 0;
}
