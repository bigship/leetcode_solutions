// 957. Prison Cells After N Days
/*
 * There are 8 prison cells in a row, and each cell is either occupied or vacant.
Each day, whether the cell is occupied or vacant changes according to the following rules:

    If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
    Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation:
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
*/
// 先找出循环节, 确定循环出现的长度
class Solution {
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    std::set<vector<int>> s;
    vector<vector<int>> prisonCells;
    while (true) {
      vector<int> next;
      if (prisonCells.empty())
        next = getNext(cells);
      else
        next = getNext(prisonCells.back());
      if (s.count(next) != 0) {
        break;
      } else {
        prisonCells.push_back(next);
        s.insert(next);
      }
    }

    int cycleLength = prisonCells.size();
    int remaining = N % cycleLength;
    if (remaining == 0)
      return prisonCells[cycleLength - 1];
    return prisonCells[remaining - 1];
  }
private:
  vector<int> getNext(vector<int>& cells) {
    vector<int> ret(cells.size(), 0);
    for (int i = 1; i < cells.size() - 1; i++) {
      if (cells[i - 1] == cells[i + 1]) {
        ret[i] = 1;
      } else {
        ret[i] = 0;
      }
    }
    if (cells[cells.size() - 1] == 1) {
      ret[cells.size() - 1] = 0;
    }
    if (cells[0] == 1) {
      ret[0] = 0;
    }
    return ret;
  }
};

