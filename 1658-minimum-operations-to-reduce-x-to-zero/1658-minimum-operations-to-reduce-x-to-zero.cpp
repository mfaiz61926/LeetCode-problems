class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        // vector<int>pref(n);
        // pref[0] = nums[0];
        // // for(int i = 1; i < n; i++){
        // //     pref[i] = pref[i - 1] + sum[i];
        // // }
        

        int total = accumulate(nums.begin(), nums.end(), 0);
        int val = total - x;
        int len = -1;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(l <= r && sum > val){
                sum -= nums[l++];
            }
            if(sum == val){
                len = max(len, r - l + 1);
            }
        }
        if(len == -1) return -1;
        return n - len;
    }
};