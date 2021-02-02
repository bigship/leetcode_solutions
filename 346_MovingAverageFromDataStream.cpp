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

// 与其每次都求一遍和, 其实只需要用一个变量维护当前队列里的和即可
// 如果队列长度满足了size, 下一次加入新的元素时将队列头部的元素pop出去
// 更新cursum即可
class MovingAverage2 {
public:
  MovingAverage(int size) {
    this->size = size;
  }

  double next(int val) {
    if (q.size() < size) {
      q.push_back(val);
      cursum += val;
      return cursum * 1.0 / q.size();
    } else {
      int last = q.front();
      cursum -= last;
      cursum += val;
      q.pop_front();
      q.push_back(val);
      return cursum * 1.0 / q.size();
    }
  }
private:
  std::deque<int> q;
  int cursum = 0;
  int size = 0;
};
