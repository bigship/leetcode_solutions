// 1396. Design Underground System
/*
 * Implement the UndergroundSystem class:

    void checkIn(int id, string stationName, int t)
        A customer with a card id equal to id, gets in the station stationName at time t.
        A customer can only be checked into one place at a time.
    void checkOut(int id, string stationName, int t)
        A customer with a card id equal to id, gets out from the station stationName at time t.
    double getAverageTime(string startStation, string endStation)
        Returns the average time to travel between the startStation and the endStation.
        The average time is computed from all the previous traveling from startStation to endStation that happened directly.
        Call to getAverageTime is always valid.

You can assume all calls to checkIn and checkOut methods are consistent.
If a customer gets in at time t1 at some station, they get out at time t2 with t2 > t1.
All events happen in chronological order.
*/

class UndergroundSystem {
public:
  UndergroundSystem() {  }

  void checkIn(int id, string stationName, int t) {
    in[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const auto &[startStation, timeIn] = in[id];
    auto &[totalDuration, tripsCnt] = stats[startStation + ">" + stationName];
    totalDuration += t - timeIn;
    ++tripsCnt;
  }

  double getAverageTime(string startStation, string endStation) {
    auto [totalDuration, tripsCnt] = stats[startStation + ">" + endStation];
    return (double)totalDuration / tripsCnt;
  }
private:
  unordered_map<int, pair<string, int>> in;
  unordered_map<string, pair<int, int>> stats;
};
