// 170. Two Sum III Data Structure Design
/*
 * Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:
    TwoSum() Initializes the TwoSum object, with an empty array initially.
    void add(int number) Adds number to the data structure.
    boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
*/

class TwoSum {
public:
  /** Initialize your data structure here. */
  TwoSum() {

  }

  /** Add the number to an internal data structure.. */
  void add(int number) {
    store.insert(number);  // log(n)
  }

  /** Find if there exists any pair of numbers which sum is equal to the value. */
  // O(n)
  bool find(int value) {
    if (store.size() < 2)
      return false;
    auto l = store.begin();
    auto r = std::prev(store.end());
    while (l != r) {
      if (*l + *r == value)
        return true;
      else if (*l + *r > value) {
        r--;
      } else {
        l++;
      }
    }
    return false;
  }
private:
  std::multiset<int> store;
};

