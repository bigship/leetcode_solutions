// 223. Rectangle Area
/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
   Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 */

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long areaA = (C-A) * (D-B);
    long areaB = (G-E) * (H-F);

    int left   = max(A, E);
    int right  = min(G, C);
    int bottom = max(F, B);
    int top    = min(D, H);

    int overlap = 0;
    if (right > left && top > bottom)
       overlap = (right - left) * (top - bottom);

    return static_cast<int>(areaA + areaB - overlap);
  }
};


