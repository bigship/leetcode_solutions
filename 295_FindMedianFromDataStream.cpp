// 295. Find Median from Data Stream
/*
 * Median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value. So the median is the mean of the two middle value.
For example,

[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

  void addNum(int num) - Add a integer number from the data stream to the data structure.
  double findMedian() - Return the median of all elements so far.

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

Follow up:

    If all integer numbers from the stream are between 0 and 100, how would you optimize it?
    If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

class MedianFinder {
public:
  MedianFinder() {

  }

  // Solution: insert new value and keep the data sorted.
  // Use binary search to find the index that new data inserted.
  void addNum(int num) {
    if (store.empty()) {
      store.push_back(num);
    } else {
      store.insert(lower_bound(store.begin(), store.end(), num), num);
    }
  }

  double findMedian() {
    int n = store.size();
    return n & 1 ? store[n / 2] : ((double)store[n/2-1] + store[n/2]) * 0.5;
  }

private:
  vector<int> store;
};

// 利用两个堆. 将全部元素划分为两个左右部分. 左边使用大顶堆右边使用小顶堆
// 则两个堆的堆顶就维护了整个数据流的中间部分
class MedianFinder {
public:
  MedianFinder() {  }

  void addNum(int num) {
    if (left.empty() || num < left.top()) {
      left.push(num);
    } else {
      right.push(num);
    }

    // balance two heaps
    if (left.size() - right.size() == 2) {
      int top = left.top();
      left.pop();
      right.push(top);
    } else if (right.size() - left.size() == 2) {
      int top = right.top();
      right.pop();
      left.push(top);
    }

  }

  double findMedian() {
    if (left.size() == right.size()) {
      return (left.top() + right.top()) / 2.0;
    }
    return left.size() > right.size() ? left.top() * 1.0 : right.top() * 1.0;
  }
private:
  priority_queue<int, vector<int>> left; // maxHeap
  priority_queue<int, vector<int>, std::greater<int>> right;  // minHeap
};




