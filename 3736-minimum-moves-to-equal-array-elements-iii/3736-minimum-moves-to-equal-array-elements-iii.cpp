class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            cnt += (mx-nums[i]);
        }
        return cnt;
    }
};