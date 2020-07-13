// 849. Maximize Distance to Closest Person
//
/* In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.



Constraints:

    2 <= seats.length <= 20000
    seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

class Solution {
public:
    // calculate left, middle, right possible position and get the max value of them
    int maxDistToCloset(vector<int>& seats) {
        vector<int> sitPosition;
        int n = seats.size();
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) sitPosition.push_back(i);
        }
        if (sitPosition.size() == 1) {
            return std::max(sitPosition[0], n - 1 - sitPosition[0]);
        }

        int ans = 0;
        for (int i = 1; i < sitPosition.size(); i++) {
            ans = std::max(ans, sitPosition[i] - sitPosition[i - 1]);
        }

        return std::max(ans / 2, std::max(sitPosition[0], n - 1 - sitPosition[sitPosition.size() - 1]));
    }
};


