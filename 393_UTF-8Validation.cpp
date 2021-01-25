// 393. UTF-8 Validation
/*
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data.
This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
*/

class Solution {
public:
  bool validUtf8(vector<int>& data) {
    vector<int> masks{0x80, 0x40, 0x20, 0x10, 0x08};
    int i = 0, j = 0;
    while (i < data.size() && j < data.size()) {
      char c = static_cast<char>(data[i] & 0xff);
      int byteslong = checkFirstByte(c, masks);
      if (byteslong == -1) {
        return false;
      }
      if (byteslong == 1) {
        i++;
        continue;
      }

      j = i + 1;
      if (i + byteslong - 1 >= data.size()) {
        return false;
      }
      while (j < i + byteslong && j < data.size()) {
        char c = static_cast<char>(data[j] & 0xff);
        if (!checkContentByte(c)) {
          return false;
        }
        j++;
      }
      i = j;
    }
    return true;
  }
private:
  int checkFirstByte(char c, vector<int>& masks) {
    int cnt = 0;
    for (int i = 0; i < masks.size(); i++) {
      if (i == 0) {
        if ((c & masks[i]) == 0)
          return 1;
        else
          cnt++;
      } else {
        if ((c & masks[i]) == masks[i]) {
          cnt++;
        } else {
          if (cnt == 2 || cnt == 3 || cnt == 4) {
            return cnt;
          } else {
            return -1;
          }
        }
      }
    }
    return -1;
  }

  bool checkContentByte(char c) {
    if (((c & 0x80) == 0x80) && ((c & 0x40) == 0))
      return true;
    return false;
  }
};


