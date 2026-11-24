class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                long long p = 1;
                long long g = 0;
                long long l = 1;
                for(int k = i; k <= j; k++){
                    p *= nums[k];
                    if(p > 250000){
                        break;
                    }
                    g = gcd(g, nums[k]);
                    l = (l * nums[k]) / gcd(l, nums[k]);
                }

                if(p == (l * g)){
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};