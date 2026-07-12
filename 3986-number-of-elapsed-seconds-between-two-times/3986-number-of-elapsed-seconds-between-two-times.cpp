class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int ans = 0;
        int hr = stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0, 2));
        int mn = stoi(endTime.substr(3, 2)) - stoi(startTime.substr(3, 2));
        int sec = stoi(endTime.substr(6, 2)) - stoi(startTime.substr(6, 2));

        ans = ans + sec + 60 * mn + 3600 * hr;
        return ans;
    }
};