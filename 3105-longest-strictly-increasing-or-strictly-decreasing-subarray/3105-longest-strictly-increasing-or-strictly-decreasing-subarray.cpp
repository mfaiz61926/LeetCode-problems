class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int maxInc = 0, maxDec = 0;
        int n=nums.size();
        if(n==1)return 1;
        
        for (int i = 1; i < n; i++) {
            bool isSmaller = false, isGreater = false;
            int countIncrease = 1, countDecrease = 1;

            for (int j = i; j < n; j++) {

                if (nums[j] > nums[j - 1] && !isSmaller) {
                    isGreater = true;
                    countIncrease++;
                } else if (nums[j] < nums[j - 1] && !isGreater) {
                    isSmaller = true;
                    countDecrease++;
                } else
                    break;
            }
            maxInc = max(countIncrease, maxInc);
            maxDec = max(countDecrease, maxDec);
        }
        return max(maxInc, maxDec);
    }
};