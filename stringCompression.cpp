// 443. String Compression

/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Follow up:
Could you solve it using only O(1) extra space?

Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.

Note:

    All characters have an ASCII value in [35, 126].
    1 <= len(chars) <= 1000.

*/

// O(1) space, in-place; O(n) time complexity

class Solution {
public:
  int compress(vector<char>& chars) {
    int cnt = 1, writePos = 0;
    for (int i = 0; i < chars.size(); i++) {
      int j = i + 1;
      if (j == chars.size() || chars[i] != chars[j]) {
        if (cnt == 1) {
          chars[writePos++] = chars[i];
        } else {
          string cntStr = std::to_string(cnt);
          chars[writePos++] = chars[i];
          for (int k = 0; k < cntStr.size(); k++) {
            chars[writePos++] = cntStr[k];
          }
          cnt = 1;
        }
        if (j == chars.size()) break;
      } else {
        cnt++;
      }
    }
    return writePos;
  }
};

class Solution2 {
public:
  int compress(vector<char>& chars) {
    if (chars.size() == 1) return 1;
    int i = 1;
    int idx = 0;
    while (i < chars.size()) {
      int cnt = 1;
      int j = i - 1;
      while (i < chars.size() && chars[j] == chars[i]) {
        cnt++;
        i++;
        j++;
      }
      chars[idx++] = chars[j];
      if (cnt != 1) {
        string cntstr = std::to_string(cnt);
        for (int k = 0; k < cntstr.length(); k++) {
          chars[idx++] = cntstr[k];
        }
      }
      i++;
      if (i == chars.size() && chars[i - 1] != chars[i - 2]) {
        chars[idx++] = chars[i - 1];
        break;
      }
    }
    return idx;
  }
};
