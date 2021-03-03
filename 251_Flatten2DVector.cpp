// 251. Flatten 2D Vector
/*
 * Design and implement an iterator to flatten a 2d vector.
 * It should support the following operations: next and hasNext.

Example:

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

Notes:
    Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases.
    Please see here for more details.
    You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.
*/

// Solution 1: 构造函数中直接把2维数组转成1维, 维护idx即可
class Vector2D {
public:
  Vector2D(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
      for (auto& val : v[i]) {
        arr.push_back(val);
      }
    }
    this->size = arr.size();
  }

  int next() {
    int res = arr[idx];
    idx++;
    return res;
  }

  bool hasNext() {
    if (idx < size) {
      return true;
    }
    return false;
  }
private:
  vector<int> arr;
  int size;
  int idx = 0;
};


// Solution 2. 只使用两个变量即可, 模拟iterator
class Vector2D {
  int row;
  int col;
  vector<vector<int>> data;

public:
   Vector2D(vector<vector<int>>& vec2d) {
     data = vec2d;
     row = 0;
     col = 0;
   }

   int next() {
     hasNext();
     return data[row][col++];
   }

   bool hasNext() {
     while (row < data.size() && data[row].size() == col)
       row++, col = 0;
     return row < data.size();
   }
};
