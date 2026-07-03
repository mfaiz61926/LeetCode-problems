class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(f < i) return false;
            f = max(f, i + nums[i]);
        }
        return true;
    }
};