class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0, pos = 0;
        for(auto & i:nums){
            xr ^= i;
            if(i>0)pos = 1;
        }

        if(xr) return n;
        return (pos==1? n-1:0);
    }
};