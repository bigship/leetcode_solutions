// 1256. Encode Number
/*
 * Given a non-negative integer num, Return its encoding string.

The encoding is done by converting the integer to a string using a secret
function that you should deduce from the following table:

n       f(n)
0        ""
1        "0"
2        "1"
3        "00"
4        "01"
5        "10"
6        "11"
7        "000"
*/

class Solution {
public:
    /*
    Assume g(n) = "1" + f(n)
    we can find:
    g(0) = "1" g(1) = "10" g(2) = "11" g(3) = "100" g(4) = "101" g(5) = "110" g(6) = "111"

    Now everything is obvious:
    g(n) = binary(n + 1)
    "1" + f(n) = binary(n + 1)
    f(n) = binary(n + 1).remove the first '1'

    */
    // f(n)加一个前缀'1', 组成的二进制字符串刚好表示了 n + 1 的二进制
  string encode(int num) {
    auto str = std::bitset<32>(num + 1).to_string();
    //cout << "str = " << str << endl;
    return str.substr(str.find('1') + 1);
  }
};


