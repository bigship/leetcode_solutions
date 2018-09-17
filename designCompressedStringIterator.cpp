// 604. Design Compressed String Iterator

/*
 Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '

*/

class StringIterator {
public:
    StringIterator(string compressedString) {
      it = 0;
      int len = compressedString.size();
      int sum = 0;
      int digit = 0;
      deque<int> dq;
      for (int i = 0; i < len; i++) {
        if (isalpha(compressedString[i])) {
          chars.push_back(compressedString[i]);
        } else {
          while (i < len && isdigit(compressedString[i])) {
            digit = compressedString[i] - '0';
            dq.push_front(digit);
            i++;
          }
          --i;
          for (int j = 0; j < dq.size(); j++) {
            dq[j] *= static_cast<int>(pow(10, j));
          }
          for (int k = 0; k < dq.size(); k++) {
            sum += dq[k];
          }
          freqs.push_back(sum);
          dq.clear();
          sum = 0;
        }
      }
    }
    
    char next() {
      if (freqs[it] == 0) {
        if (it != freqs.size() - 1) {
          ++it;
          freqs[it]--;
          return chars[it];
        } else {
          return ' ';
        }
      } else {
        freqs[it]--;
        return chars[it];
      }
    }
    
    bool hasNext() {
      if (freqs[it] != 0) {
        return true;
      } else {
        return it != (freqs.size() - 1);
      }
    }
private:
  vector<int> freqs;
  vector<char> chars;
  int it;
};