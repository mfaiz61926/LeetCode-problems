class Solution {
public:
    bool check(int mid, vector<int>&start, int d){
        long long prev = start[0];
        for(int i = 1; i < start.size(); i++){
            long long next = max(prev + 1LL * mid, 1LL * start[i]);
            if(next > start[i] + d) return false;
            prev = next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());

        int low = 0; 
        int high = start[n - 1] - start[0] + d;

        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, start, d)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};