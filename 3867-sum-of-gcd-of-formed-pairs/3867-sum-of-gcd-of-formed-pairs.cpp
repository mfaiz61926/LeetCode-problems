class Solution {
public:
    int g(int a, int b){
        if(b == 0) return a;
        return g(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>mx(n);
        mx[0] = nums[0];

        for(int i = 1; i < n; i++){
            mx[i] = max(mx[i - 1], nums[i]);
        }

        vector<int>prefixGcd(n);
        for(int i = 0; i < n; i++){
            prefixGcd[i] = g(nums[i], mx[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n - 1;
        long long sum = 0;
        while(i < j){
            long long gg = 0;
            gg = g(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
            sum += gg;
        }

        return sum;
    }
};