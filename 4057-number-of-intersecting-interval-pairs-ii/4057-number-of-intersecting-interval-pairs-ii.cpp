class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long  cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++){
            int x1 = intervals[i][0];
            int y1 = intervals[i][1];
            // for(int j = i + 1; j < n; j++){
            //     int x2 = intervals[j][0];
            //     int y2 = intervals[j][1];
            //     if(x1 <= x2 && x2 <= y1 || x1 <= y2 && y2 <= y1 || x2 <= x1 && y1 <= y2) cnt++;
            // }
            int low = i + 1;
            int high = n - 1;
            int ans = 0;
            while(low <= high){
                int mid = low + (high - low) / 2;
                auto it = intervals[mid];
                int x2 = it[0];
                int y2 = it[1];

                if(y1 >= x2){
                    low = mid + 1;
                    ans = mid;
                }
                else high = mid - 1;
            }
            if(ans > 0) cnt += ans - i;
        }
        return cnt;
    }
    
};