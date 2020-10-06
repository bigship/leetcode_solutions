// 1079. Letter Tile Possibilities
/*
 * You have n tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the
letters printed on those tiles.

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:

Input: tiles = "AAABBC"
Output: 188

Example 3:

Input: tiles = "V"
Output: 1

Constraints:

    1 <= tiles.length <= 7
    tiles consists of uppercase English letters.
*/
class Solution {
public:
  // Solution: Combination + Permutation
  // 先产生所有不重复的组合形式, 针对每个组合的情况计算全排列的个数, 累加就是结果
  // 注意: 使用next_permutation前需要对序列做排序. 可能出现排序后的组合是相同的情况, 此时必须去除掉
  // 排序后结果相同的组合. (例如: CDC   CD和DC排序后结果一致, 不能重复计算)
  int numTilePossibilities(string tiles) {
    vector<char> cur;
    vector<string> combo;

    function<void(int)> helper = [&](int start) {
      for (int i = start; i < tiles.length(); i++) {
        cur.push_back(tiles[i]);
        combo.push_back(string(cur.begin(), cur.end()));
        if (i < tiles.length()) {
          helper(i + 1);
        }
        cur.pop_back();
      }
    };

    helper(0);
    std::sort(combo.begin(), combo.end());
    combo.erase(std::unique(combo.begin(), combo.end()), combo.end());

    int cnt = 0;
    unordered_map<string, int> map;
    for (int i = 0; i < combo.size(); i++) {
      string cur = combo[i];
      std::sort(cur.begin(), cur.end());
      if (map.find(cur) == map.end()) {
        map[cur] = 1;
      } else {
        continue;
      }

      do {
        cnt++;
      } while (std::next_permutation(cur.begin(), cur.end()));
    }

    return cnt;
  }

  // 使用回溯法. 先统计字母出现的次数
  int numTilePossibilities_backtrack(string tiles) {
    vector<int> m(26, 0);
    for (auto& c : tiles)
      m[c - 'A']++;

    return backtrack(m);
  }
private:
  int backtrack(vector<int>& m) {
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      if (m[i] == 0) continue;
      m[i]--;
      sum++;
      sum += backtrack(m);
      m[i]++;
    }
    return sum;    // 把结果返回给上一层
  }
};

