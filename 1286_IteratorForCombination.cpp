// 1286. Iterator for Combination
/*
 * Design an Iterator class, which has:

    A constructor that takes a string characters of sorted distinct lowercase
    English letters and a number combinationLength as arguments.
    A function next() that returns the next combination of length combinationLength in lexicographical order.
    A function hasNext() that returns True if and only if there exists a next combination.

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

Constraints:
    1 <= combinationLength <= characters.length <= 15
    There will be at most 10^4 function calls per test.
    It's guaranteed that all calls of the function next are valid.
*/

class CmbinationIterator {
public:
  CombinationIterator(string characters, int combinationLength) {
    db = vector<string>();
    idx = 0;
    start = 0;
    generateCombination(characters, "", start, combinationLength);
  }

  string next() {
    return db[idx++];
  }

  bool hasNext() {
    return idx < db.size();
  }
private:
  vector<string> db;
  int idx;
  int start;

  void generateCombination(string characters, string cur, int start, int len) {
    if (cur.size() == len) {
      db.push_back(cur);
      return ;
    }
    for (int i = start; i < characters.size(); i++) {
      cur += characters[i];
      generateCombination(characters, cur, i+1, len);
      cur.pop_back();
    }
  }
};

