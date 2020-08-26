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

int main() {
  //string input = "tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao";
  string input = "aaaabca";
  cout << Solution().reorganizeString(input) << endl;
  return 0;
}
