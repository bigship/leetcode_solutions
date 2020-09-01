// 1441. Build an Array With Stack Operations
/*
 * Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.
Build the target array using the following operations:

    Push: Read a new element from the beginning list, and push it in the array.
    Pop: delete the last element of the array.
    If the target array is already built, stop reading more elements.

You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.
Return the operations to build the target array.
You are guaranteed that the answer is unique.

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation:
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]

Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.

Example 4:

Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]

Constraints:

  1 <= target.length <= 100
  1 <= target[i] <= 100
  1 <= n <= 100
  target is strictly increasing.
*/

class Solution {
public:
  // 顺序比较target上的数和1 - n之间的数, 如果相同则添加Push
  // 如果出现target上的数比对应的1-n之间的数要大, 表示中间出现过Pop
  // 那么一共需要经过target[j] - i组Push和Pop
  // 注意由于栈的特点是后进先出, 因此不能先Push完再Pop, 而是Push和Pop要交替进行
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int i = 1;
    int j = 0;
    while (i <= n && j < target.size()) {
      if (i == target[j]) {
        ans.push_back("Push");
        i++;
        j++;
      } else if (i < target[j]) {
        for (int x = 0; x < target[j] - i; x++) {
          ans.push_back("Push");
          ans.push_back("Pop");
        }
        i = target[j];
      }
    }
    return ans;
  }
};


