// 68. Text Justification
// Hard
/*
 * Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> fullyJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int curRowLen = 0;
    int start = 0, end = 0;

    for (int i = 0; i < words.size(); i++) {
      if ((curRowLen == 0 && curRowLen + words[i].length() <= maxWidth) ||
          (curRowLen > 0 && curRowLen + 1 + words[i].length() <= maxWidth)) {
        end++;
        if (curRowLen == 0) {
          curRowLen = curRowLen + words[i].length();
        } else {
          curRowLen = curRowLen + 1 + words[i].length();
        }
        i++;
      } else {
        // exceeds maxWidth
        // 计算还剩余多少个位置
        int remaining = maxWidth - curRowLen + (end - start) - 1;
        if (end - start == 1) {
          // 这一行就一个单词 就是单词 + 后续的空格
          string blank = getStringBlank(remaining);
          ans.push_back(words[start] + blank);
        } else {
          // 一行内有多个单词
          string tmp;
          tmp.append(words[start]);

          // 先算平均间隔需要有多少个空格
          int averageBlank = remaining / (end - start - 1);

          // 不能平均分配空格, 计算剩余空格数
          int missing = remaining - averageBlank * (end - start - 1);
          string blank = getStringBlank(averageBlank + 1);
          int k = 1;
          for (int j = 0; j < missing; j++) {
            tmp.append(blank + words[start + k]);
            k++;
          }

          blank = getStringBlank(averageBlank);
          for (; k < (end - start); k++) {
            tmp.append(blank + words[start + k]);
          }
          ans.push_back(tmp);
        }
        start = end;
        curRowLen = 0;
      }
    }

    // last line. left alignment
    string tmp;
    tmp.append(words[start]);
    for (int i = 1; i < (end - start); i++) {
      tmp.append(" " + words[start + i]);
    }
    tmp.append(getStringBlank(maxWidth - curRowLen));
    ans.push_back(tmp);
    return ans;
  }
private:
  string getStringBlank(int n) {
    string str;
    for (int i = 0; i < n; i++) {
      str.append(" ");
    }
    return str;
  }
};

class Solution2 {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> ans;
    int begin = 0;
    while (begin < words.size()) {
      int last = begin;
      int linesize = words[begin++].size();
      while (begin < words.size() && linesize + 1 + words[begin].size() <= L) {
        linesize += 1 + words[begin].size();
        begin++;
      }

      int spaces = 1, extra = 0;
      if (begin < words.size() && begin != last + 1) {
        spaces = (L - linesize) / (begin - last - 1) + 1;
        extra = (L - linesize) % (begin - last - 1);
      }

      ans.push_back(words[last++]);
      while (extra--) {
        ans.back().append(spaces+1, ' ');
        ans.back().append(words[last++]);
      }
      while (last < begin) {
        ans.back().append(spaces, ' ');
        ans.back().append(words[last++]);
      }
      ans.back().append(L-ans.back().size(), ' ');
    }

    return ans;
  }
};
