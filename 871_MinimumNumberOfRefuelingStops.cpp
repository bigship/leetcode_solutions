// 871. Minimum Number of Refueling Stops
/*
 * A car travels from a starting position to a destination which is target miles east of the starting position.
Along the way, there are gas stations.
Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
What is the least number of refueling stops the car must make in order to reach its destination?
If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

*/

// Greedy, DP
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int stops = 0;
    int curdistance = startFuel;
    std::priority_queue<int, vector<int>> maxHeap;  // record the fule in stations
    int station_idx = 0;

    while (true) {
      // We made it to target
      if (curdistance >= target) {
        return stops;
      }

      // record all the fuels in stations that we passed by
      while (station_idx < stations.size() && curdistance >= stations[station_idx][0]) {
        maxHeap.push(stations[station_idx++][1]);
      }

      // we don't have any stations can refuel
      if (maxHeap.empty()) {
        break;
      }

      // we run out of fuel, and need to refuel, pick the stations which has the most fuel
      // each station can only use once
      curdistance += maxHeap.top();
      maxHeap.pop();
      stops++;
    }

    return stops;
  }
};
