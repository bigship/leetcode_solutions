// 1244. Design A LeaderBoard
/*
 * Design a Leaderboard class, which has 3 functions:

    addScore(playerId, score): Update the leaderboard by adding score to the given player's score.
    If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
    top(K): Return the score sum of the top K players.
    reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard).
    It is guaranteed that the player was added to the leaderboard before calling this function.

Initially, the leaderboard is empty.

Example 1:

Input:
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output:
[null,null,null,null,null,null,73,null,null,null,141]

Explanation:
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;

Constraints:
    1 <= playerId, K <= 10000
    It's guaranteed that K is less than or equal to the current number of players.
    1 <= score <= 100
    There will be at most 1000 function calls.
*/

// hashmap + minHeap
// Time: O(1) for addScore, O(1) for reset, O(K) + O(NlogK) for topK
class Leaderboard {
public:
  Leaderboard() {

  }

  void addScore(int playerId, int score) {
    scoreMap[playerId] += score;
  }

  int top(int K) {
    int n = scoreMap.size();
    auto it = scoreMap.begin();
    for (; it != scoreMap.end() && K > 0; it++) {
      minHeap.push(it->second);
      K--;
    }
    while (it != scoreMap.end()) {
      if (it->second > minHeap.top()) {
        minHeap.pop();
        minHeap.push(it->second);
      }
      it++;
    }

    int res = 0;
    while (!minHeap.empty()) {
      res += minHeap.top();
      minHeap.pop();
    }
    return res;
  }

  void reset(int playerId) {
    scoreMap[playerId] = 0;
  }
private:
  std::unordered_map<int, int> scoreMap;   // key: playerId, value: score
  std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
};

// TreeMap
// O(logN) for addScore
// O(logN) for reset
// O(K) for topK
class Leaderboard2 {
public:
  Leaderboard2() {

  }

  void addScore(int playerId, int score) {
    set.erase({scores[playerId], playerId});  // remove the old score for player from set
    scores[playerId] += score;                // updates the latest score for player
    set.insert({scores[playerId], playerId}); // insert the latest score into set
  }

  int top(int K) {
    int sum = 0;
    for (auto it = set.rbegin(); it != set.rend() && K > 0; it++) {
      K--;
      sum += it->first;
    }
    return sum;
  }

  void reset(int playerId) {
    set.erase({scores[playerId], playerId});  // remove the score from set
    scores[playerId] = 0;                     // reset player score back to 0
  }

private:
  std::unordered_map<int, int> scores;
  std::set<pair<int, int>> set;  // <score, player id>
};

