class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long mid = nums[n/2];

        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (abs(mid - nums[i]));
        }

        return cnt;
    }
};