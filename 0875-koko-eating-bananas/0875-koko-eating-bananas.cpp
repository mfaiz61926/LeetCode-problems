class Solution {
public:
    bool check(vector<int>&piles, int mid, int h){
        long long cnt = 0;
        for(auto &i : piles){
            cnt += (i + mid - 1) / mid;
        }
        return cnt <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};