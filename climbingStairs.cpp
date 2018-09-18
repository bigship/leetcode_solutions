// 70. Climbing Stairs

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

// recursion with cache support

class Solution {
public:
  int climbStairs(int n) {
    unordered_map<int, int> cache;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    return helper(cache, n);
  }
private:
  int helper(unordered_map<int, int>& cache, int n) {
    if (cache.find(n) != cache.end()) {
      return cache[n];
    } else {
      cache[n] = helper(cache, n - 1) + helper(cache, n - 2);
      return cache[n];
    }
  }
}