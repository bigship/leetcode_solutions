// 46. Permutations
/*
 * Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n);       // 每个元素只能选一次, 记录已选过的值
        vector<int> out;           // 记录选择的路径

        function<void(int)> helper = [&](int start) {
            if (start == n) {         // 已经全部选完, 把路径添加到最终结果
                ans.push_back(out);
                return ;
            }

            for (int i = 0; i < n; i++) {
                if (used[i]) continue;       // 已经选过了, 不能再选
                used[i] = 1;                 // 标记为已选
                out.push_back(nums[i]);      // 添加到路径中
                helper(start+1);             // 开始递归 , 返回之后就是回溯
                out.pop_back();              // 撤销选择
                used[i] = 0;                 // 重新标记为可用
            }
        };

        helper(0);
        return ans;
    }
};

