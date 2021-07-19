// 789. Escape The Ghosts
/*
 * You are playing a simplified PAC-MAN game on an infinite 2-D grid.
 * You start at the point [0, 0], and you are given a destination point target = [xtarget, ytarget], which you are trying to get to.
 * There are several ghosts on the map with their starting positions given as an array ghosts, where ghosts[i] = [xi, yi] represents the starting position of the ith ghost. All inputs are integral coordinates.

Each turn, you and all the ghosts may independently choose to either move 1 unit in any of the four cardinal directions: north, east, south, or west or stay still.
All actions happen simultaneously.

You escape if and only if you can reach the target before any ghost reaches you.
If you reach any square (including the target) at the same time as a ghost, it does not count as an escape.
Return true if it is possible to escape, otherwise return false.

*/

// 由于ghost可以选择不移动. 因此只要有ghost比pacman先到终点, 它只要等着不动即可, 那么此时pacman一定无法逃脱出去.
// 所以可以表达成: 所有ghost到target的最短距离与pacman到target的最短距离做比较. 只要有任意一个ghost会比pacman先到达
// 终点, 那么就不可能逃脱出去.
class Solution {
public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int pac = shortestPath(0, 0, target);
    for (int i = 0; i < ghosts.size(); i++) {
      if (pac >= shortestPath(ghosts[i][0], ghosts[i][1], target)) {
        return false;
      }
    }
    return true;
  }
private:
  // Infinite 2D grid
  int shortestPath(int x, int y, vector<int>& target) {
    return abs(target[0] - x) + abs(target[1] - y);
  }
};


