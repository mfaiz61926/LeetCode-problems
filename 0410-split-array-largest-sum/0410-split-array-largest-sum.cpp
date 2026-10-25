class Solution {
public:
    bool check(int mid, vector<int>&nums, int k){
        int load = 0;
        int cnt = 1;
        for(auto &i : nums){
            if(load + i > mid){
                cnt++;
                load = i;
            }
            else load += i;
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, nums, k)){
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