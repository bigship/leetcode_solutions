// 412. Fizz Buzz

/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 

For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans(n, "1");
    for (int i = 0; i < n; i++) {
      if ((i+1) % 3 == 0 && (i+1) % 5 == 0) {
        ans[i] = "FizzBuzz";
        continue;
      }
      if ((i+1) % 3 == 0) {
        ans[i] = "Fizz";
        continue;
      }
      if ((i+1) % 5 == 0) {
        ans[i] = "Buzz";
        continue;
      }
      ans[i] = to_string(i+1); 
    }
    return ans;
  }
};

