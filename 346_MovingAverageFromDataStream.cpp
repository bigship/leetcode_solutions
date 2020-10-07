// 346. Moving Average from Data Stream
/*
 * Given a stream of integers and a window size, calculate the moving average of
 * all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
  // Solution: 使用双端队列, 元素不够k个时就往后插入 计算平均值
  // 元素达到k个之后, 每次把新元素添加到最后, 并把队列最前的元素移除
  // deque可保证从头尾的插入删除操作都是O(1)
  MovingAverage(int size) {
    k = size;
  }

  double next(int val) {
    k.push_back(val);
    int n = q.size();
    if (n <= k) {
      int s = std::accumulate(q.begin(), q.end(), 0);
      return static_cast<double>(s) / n;
    } else {
      q.pop_front();
      int s = std::accumulate(q.begin(), q.end(), 0);
      return static_cast<double>(s) / k;
    }
  }
private:
  std::deque<int> q;
  int k;
};
