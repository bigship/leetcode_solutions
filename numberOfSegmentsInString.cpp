// 434. Number of Segments in a String

/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

class Solution {
public:
  /*
  int countSegments(string s) {
    istringstream ss(s);
    int cnt = 0;
    while (ss >> s) cnt++;
    return cnt;
  }*/

  int countSegments(string s) {
    int inword = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (inword == 0) {
          inword = 1;
          cnt++;
        }
      } else {
        if (inword == 1) {
          inword = 0;
        }
      }
    }
    return cnt;
  }
};