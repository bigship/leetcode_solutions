// 839. Similar String Groups
/*
 * Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
 * Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.
Notice that "tars" and "arts" are in the same group even though they are not similar.
Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.
*/

// 并查集
// 两个字符串能否通过交换一次idx上的字符变成相同, 表示它们错位的字符只能有2个.
// 如果可以通过交换变成相同, 就将它们合并到一组. 已经合并过的就不再合并
// 每合并一次, 总的数量减去1. 最后得到的groups数量就是答案

class Solution {
public:
  int numSimilarGroups(vector<string>& strs) {
    int groups = strs.size();
    UnionFind uf(groups);

    for (int i = 0; i < strs.size(); i++) {
      for (int j = i + 1; j < strs.size(); j++) {
        if (canSwap(strs[i], strs[j]) && uf.unionGroup(i, j)) {
          groups--;
        }
      }
    }
    return groups;
  }
private:
  bool canSwap(const string& str1, const string& str2) {
    int misMatch = 0;
    for (int i = 0; i < str1.length(); i++) {
      if (str1[i] != str2[i]) {
        misMatch++;
        if (misMatch > 2) return false;
      }
    }
    return misMatch == 0 || misMatch == 2;
  }

  class UnionFind {
    vector<int> group;
    vector<int> rank;
  public:
    UnionFind(int size) {
      group = vector<int>(size, 0);
      rank = vector<int>(size, 0);
      for (int i = 0; i < size; i++) {
        group[i] = i;
      }
    }

    int find(int id) {
      if (group[id] != id) {
        group[id] = find(group[id]);
      }
      return group[id];
    }

    bool unionGroup(int id1, int id2) {
      int g1 = find(id1);
      int g2 = find(id2);
      if (g1 == g2) return false;

      int r1 = rank[g1];
      int r2 = rank[g2];
      if (r1 < r2) {
        group[g1] = g2;
      } else if (r1 > r2) {
        group[g2] = g1;
      } else {
        group[g1] = g2;
        rank[g2]++;
      }
      return true;
    }
  };
};




