class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>a;
        int n = nums.size();
        for(auto &i : nums) a.push_back(abs(i));
        sort(a.begin(), a.end());
        for(auto &i : a) cout << i << " ";
        cout << endl;
        long long sum = 0;
        for(int i = 0; i < n / 2; i++) sum -= a[i] * a[i];
        for(int i = n / 2; i < n; i++) sum += a[i] * a[i];
        return sum;
    }
};