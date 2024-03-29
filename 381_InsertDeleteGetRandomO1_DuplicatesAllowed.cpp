// 381. Insert Remove GetRandom O(1) - Duplicates allowed
/*
 * Implement the RandomizedCollection class:

RandomizedCollection() Initializes the RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise.
Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called).
The probability of each element being returned is linearly related to the number of same values the multiset contains.

Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.

Constraints:

-2^31 <= val <= 2^31 - 1
At most 10^5 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.
*/

class RandomizedCollections {
public:
  RandomizedCollections() {  }

  bool insert(int val) {
    m[val].push_back(vals.size());
    vals.emplace_back(val, m[val].size() - 1);
    return m[val].size() == 1u;
  }

  bool remove(int val) {
    if (!m.count(val)) return false;
    int idx_evict = m[val].back();
    const auto& last_entry = vals.back();
    m[last_entry.first][last_entry.second] = idx_evict;
    std::swap(vals.back(), vals[idx_evict]);
    vals.pop_back();
    m[val].pop_back();
    if (m[val].empty()) {
      m.erase(val);
    }
    return true;
  }

  int getRandom() {
    return vals[rand() % vals.size()].first;
  }
private:
  unordered_map<int, vector<int>> m;   // val -> indices array (indices in vals)
  vector<pair<int, int>> vals;         // {val, index in the indices array}
};

