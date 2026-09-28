class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();

        for(int i = 0; i < n; i++){
            int x1 = intervals[i][0];
            int y1 = intervals[i][1];
            for(int j = i + 1; j < n; j++){
                int x2 = intervals[j][0];
                int y2 = intervals[j][1];
                if(x1 <= x2 && x2 <= y1 || x1 <= y2 && y2 <= y1 || x2 <= x1 && y1 <= y2) cnt++;
            }
        }
        return cnt;
    }
};