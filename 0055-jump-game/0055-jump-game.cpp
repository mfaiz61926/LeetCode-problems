class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = nums[0];
        for(int i = 1; i < n; i++){
            if(farthest < i) return false;
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};