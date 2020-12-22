// 380. Insert Delete GetRandom O(1)
/*
 * Implement the RandomizedSet class:

    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements
    (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

Follow up: Could you implement the functions of the class with each function works in average O(1) time?

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.

Constraints:

    -231 <= val <= 231 - 1
    At most 105 calls will be made to insert, remove, and getRandom.
    There will be at least one element in the data structure when getRandom is called.
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
  RandomizedSet() {

  }

  // 插入时判断hashmap中是否已有, 若已有则返回false
  // 若hashmap中不存在, 插入vector尾部O(1), 同时在hashmap中记录该值以及该值在vector中对应的下标
  bool insert(int val) {
    if (check.find(val) != check.end())
      return false;

    store.push_back(val);
    int idx = store.size() - 1;
    check[val] = idx;
    return true;
  }

  // 删除时先看hashmap中是否已存在该值. 若不存在直接返回false
  // 若存在, 先从hashmap中取得该值在vector中对应的下标
  // 将该值和vector尾部的值交换, 然后pop_back() O(1)
  // 更新hashmap中交换过的值对应的新下标. 最后从hashmap中删除移除出去的值
  bool remove(int val) {
    if (check.find(val) != check.end()) {
      int idx = check[val];
      int lastidx = store.size() - 1;
      std::swap(store[idx], store[lastidx]);
      store.pop_back();
      check[store[idx]] = idx;
      check.erase(val);
      return true;
    }
    return false;
  }

  // 随机取得一个下标, 返回对应下标的值即可
  int getRandom() {
    int n = store.size();
    return store[rand() % n];
  }
private:
  vector<int> store;
  unordered_map<int, int> check;
};

