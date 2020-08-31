// 6. ZigZag Conversion
/*
 *The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/
class Solution() {
public:
    // 将格式化的结果保存下来
    // 把每一列的结果保存在vector<char>内
    // 找规律, 写满的列必须满足 i % (numRows - 1) == 0, 遇到写满的列则重置pos为numRows - 2
    // 下标pos表示在写不满的列中需要填入字符的下标, 由于这种列只写入一个字符, 因此写完就break出去
    // 在循环中判断写入字符的索引, 如果超过原字符串长度则退出循环
    // 时间复杂度O(n*numRows), 空间复杂度O(n)
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> grid;
        vector<char> col(numRows, '#');
        int idx = 0;
        int pos = 0;
        for (int i = 0; i < s.length() && idx < s.length(); i++) {
            for (int j = 0; j < numRows && idx < s.length(); j++) {
                if (i % (numRows - 1) == 0) {
                    col[j] = s[idx++];
                    pos = numRows - 2;
                } else {
                    col[pos--] = s[idx++];
                    break;
                }
            }
            grid.push_back(col);
            vector<char>(numRows, '#').swap(col);
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == '#') continue;
                ans += grid[j][i];
            }
        }
        return ans;
    }
};

