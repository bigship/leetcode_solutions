// 991. Broken Calculator
/*
 * On a broken calculator that has a number showing on its display, we can perform two operations:
    Double: Multiply the number on the display by 2, or;
    Decrement: Subtract 1 from the number on the display.

Initially, the calculator is displaying the number X.
Return the minimum number of operations needed to display the number Y.

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.

Example 2:

Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.

Example 3:

Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.

Example 4:

Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.

Note:

    1 <= X <= 10^9
    1 <= Y <= 10^9
*/

// 逆向思维, 由Y转为X 可以/2, 可以+1
// 根据数据规模 10^9 算法至少要为log级别
// 让Y尽可能的除以2才可以有log级的时间复杂度
// Y是偶数就除以2, 若是奇数就先加1
class Solution {
public:
  int brokenCalc(int X, int Y) {
    if (X >= Y) return X - Y;
    return 1 + brokenCalc(X, Y % 2 ? Y + 1 : Y / 2);
  }
};

