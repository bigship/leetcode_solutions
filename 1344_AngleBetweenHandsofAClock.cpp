// 1344. Angle Between Hands of a Clock
/*
 * Given two numbers, hour and minutes.
 * Return the smaller angle (in degrees) formed between the hour and the minute hand.
 */

class Solution {
public:
  double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;
    double diff = abs(hourAngle - minutesAngle);
    return std::min(diff, 360 - diff);
  }
};
