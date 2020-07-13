// 826. Most Profit Assigning Work
/*
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i]
 * is the profit of the ith job.

Now we have some workers. worker[i] is the ability of the ith worker, which means
that this worker can only complete a job with difficulty at most worker[i].
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.
If a worker cannot complete any job, his profit is $0.
What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.

Notes:

    1 <= difficulty.length = profit.length <= 10000
    1 <= worker.length <= 10000
    difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
*/

class Solution {
public:
    // Use unordered_multimap, TLE, Time - O(n^2)
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int workers = worker.size();
        int ans = 0;
        unordered_multimap<int, int> m;   // build map, difficulty : profit
        for (int i = 0; i < difficulty.size(); i++) {
            m.insert({difficulty[i], profit[i]});
        }
        for (int i = 0; i < workers; ++i) {
            ans += getProfit(m, worker[i]);
        }
        return ans;
    }

    // sort worker by skill level, sort jobs by skill level
    // Time - O(n)
    int maxProfitAssignment_sort(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = difficulty.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.emplace_back(difficulty[i], profit[i]);

        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());

        int ans = 0;
        int i = 0;
        int best = 0;
        for (int level : worker) {
            while (i < n && level >= jobs[i].first)
                best = std::max(best, jobs[i++].second);
            ans += best;
        }
        return ans;
    }
private:
    int getProfit(unordered_multimap<int, int>& m, int target) {
        int max = 0;
        auto it = m.begin();
        while (it != m.end()) {
            if (it->first <= target)
                max = std::max(max, it->second);
            ++it;
        }
        return max;
    }
};


