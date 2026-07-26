class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int far = nums[0], curJump = nums[0];
        int jump = 1;
        int i = 0; 
        while(i < n - 1){
            far = max(far, i + nums[i]);
            if(curJump == i){
                jump++;
                curJump = far;
            }
            i++;
        }
        return jump;
    }
};