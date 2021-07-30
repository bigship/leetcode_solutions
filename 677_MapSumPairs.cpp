// 677. Map Sum Pairs
/*
 * Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map.
If the key already existed, the original key-value pair will be overridden to the new one.

int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

Constraints:
1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/

class MapSum {
public:
  MapSum() {}

  void insert(string key, int val) {
    int inc = val - vals_[key];
    Trie* p = &root;
    for (const char c : key) {
      if (!p->children[c])
        p->children[c] = new Trie();
      p->children[c]->sum += inc;
      p = p->children[c];
    }
    vals_[key] = val;
  }

  int sum(string prefix) {
    Trie* p = &root;
    for (const char c : prefix) {
      if (!p->children[c])
        return 0;
      p = p->children[c];
    }
    return p->sum;
  }
private:
  struct Trie {
    Trie():children(128, nullptr), sum(0) { }
    ~Trie() {
      for (auto child : children)
        if (child) delete child;
      children.clear();
    }
    vector<Trie*> children;
    int sum;
  };

  Trie root;                        // dummy root
  unordered_map<string, int> vals_; // key -> val
};

