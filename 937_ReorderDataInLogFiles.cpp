// 937. Reorder Data in Log Files
/*
 * You have an array of logs.  Each log is a space delimited string of words.
   For each log, the first word in each log is an alphanumeric identifier. Then, either:

    Each word after the identifier will consist only of lowercase letters, or;
    Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.
It is guaranteed that each log has at least one word after its identifier.
Reorder the logs so that all of the letter-logs come before any digit-log.
The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.
The digit-logs should be put in their original order.
Return the final order of the logs.

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

Constraints:
    0 <= logs.length <= 100
    3 <= logs[i].length <= 100
    logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/

class Solution {
public:
  // Solution: Custom sorting
  vector<string> reorderLogFiles(vector<string>& logs) {
    unordered_map<string, Classifer> map;
    for (int i = 0; i < logs.size(); i++) {
      long it = logs[i].find(" ");
      if (isdigit(logs[i][it+1])) {
          Classifer c(1, i, "");
          map[logs[i]] = c;
      } else {
          Classifer c(0, -1, logs[i].substr(it+1), logs[i].substr(0, it));
          map[logs[i]] = c;
      }
    }

    std::sort(logs.begin(), logs.end(), [&](string s1, string s2) {
      if (map[s1].isDigit == 1 && map[s2].isDigit == 1) {
          return map[s1].idx < map[s2].idx;
      }
      if (map[s1].isDigit == 1 && map[s2].isDigit == 0) {
          return false;
      }
      if (map[s1].isDigit == 0 && map[s2].isDigit == 1) {
          return true;
      }
      if (map[s1].isDigit == 0 && map[s2].isDigit == 0) {
          if (map[s1].letters == map[s2].letters) {
              return map[s1].prefix < map[s2].prefix;
          }
          return map[s1].letters < map[s2].letters;
      }
      return false;
    });

    return logs;
  }

  class Classifer {
  public:
    Classifer(int isdigit=-1, int index=-1, string str="", string pre="") : isDigit(isdigit),
            idx(index), letters(str), prefix(pre)
    { }
    int isDigit;
    int idx;
    string letters;
    string prefix;
  };
};



