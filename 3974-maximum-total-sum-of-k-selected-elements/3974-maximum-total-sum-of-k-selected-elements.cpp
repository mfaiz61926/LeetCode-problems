class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        long long sum = 0, s2 = 0;

        for(int i = 0; i < k; i++){
            long long x1 = nums[i];
            long long x2 = (1LL * mul * nums[i]);
            mul--;
            sum += max(x1, x2);
        }
        return sum;
    }
};