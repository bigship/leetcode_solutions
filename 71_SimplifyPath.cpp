// 71. Simplify Path
/*
 * Given an absolute path for a file (Unix-style), simplify it.
 * Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period '.' refers to the current directory.
Furthermore, a double period '..' moves the directory up a level.

Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names.
The last directory name (if it exists) must not end with a trailing '/'.
Also, the canonical path must be the shortest string representing the absolute path.

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:

Input: path = "/a/./b/../../c/"
Output: "/c"

Constraints:

    1 <= path.length <= 3000
    path consists of English letters, digits, period '.', slash '/' or '_'.
    path is a valid Unix path.
*/

class Solution {
public:
  string simplifyPath(string path) {
    stringstream ss(path);
    string cur;
    deque<string> s;

    // 按'/'分词
    while (getline(ss, cur, '/')) {
      if (cur == "..") {
        if (!s.empty()) {
          s.pop_back();
        }
      } else if (cur != "" && cur != ".") {
        s.push_back(cur);
      }
    }

    string ans = "/";      // 起始必须有'/'
    while (!s.empty()) {
      ans += s.front();
      s.pop_front();
      if (!s.empty()) {
        res += "/";        // 没到末尾, 添加'/'分割
      }
    }

    return res;
  }
};

