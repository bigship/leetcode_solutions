// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
/*
 * Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts
 * where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly,
 * verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays
horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

*/
// Solution: 排序后找相邻差最大的部分.
class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    const int mod = 1000000000 + 7;
    std::sort(horizontalCuts.begin(), horizontalCuts.end());   // h
    std::sort(verticalCuts.begin(), verticalCuts.end());       // w
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);

    long maxwidth = horizontalCuts[0], maxheight = verticalCuts[0];
    for (int i = 1; i < horizontalCuts.size(); i++) {
      if (maxwidth < horizontalCuts[i] - horizontalCuts[i-1]) {
        maxwidth = horizontalCuts[i] - horizontalCuts[i-1];
      }
    }
    for (int j = 1; j < verticalCuts.size(); j++) {
      if (maxheight < verticalCuts[j] - verticalCuts[j-1]) {
        maxheight = verticalCuts[j] - verticalCuts[j-1];
      }
    }
    return (maxwidth * maxheight) % mod;
  }
};
