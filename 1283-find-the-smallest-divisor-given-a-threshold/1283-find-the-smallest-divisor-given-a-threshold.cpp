class Solution {
public:
    bool check(int mid, vector<int>&nums, int threshold){
        long long cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += (nums[i] + mid - 1) / mid;
        }
        return cnt <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        long long low = 1;
        long long high = *max_element(nums.begin(), nums.end());
        long long ans = -1;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(mid, nums, threshold)){
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