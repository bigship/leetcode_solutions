// 836. Rectangle Overlap
/*
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner,
 * and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.
To be clear, two rectangles that only touch at the corner or edges do not overlap.
Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Example 3:

Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false

Constraints:

    rect1.length == 4
    rect2.length == 4
    9 <= rec1[i], rec2[i] <= 109
    rec1[0] <= rec1[2] and rec1[1] <= rec1[3]
    rec2[0] <= rec2[2] and rec2[1] <= rec2[3]
*/
class Solution {
public:
  // 以一个顶点为坐标, 再以长和宽来表示矩形会更加简单
  // 枚举所有不相交的情况(注意相切的情况, 此时也不满足相交), 其余的便是相交了
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int x1 = rec1[0], y1 = rec1[1], w1 = rec1[2] - x1, h1 = rec1[3] - y1;
    int x2 = rec2[0], y2 = rec2[1], w2 = rec2[2] - x2, h2 = rec2[3] - y2;
    if (x1 < x2 && x1 + w1 <= x2) return false;
    if (x2 < x1 && x2 + w2 <= x1) return false;
    if (y1 < y2 && y1 + h1 <= y2) return false;
    if (y2 < y1 && y2 + h2 <= y1) return false;
    return true;
  }
};

