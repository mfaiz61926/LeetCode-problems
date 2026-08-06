class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long l = gcd(nums[i], nums[j]);
                long long x = (1LL * nums[i] * nums[j] ) / (l * l);
                mx = max(mx, x);
            }
        }
        return mx;
    }
};