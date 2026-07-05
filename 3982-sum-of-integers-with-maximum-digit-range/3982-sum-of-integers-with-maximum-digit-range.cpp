class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int sum = 0;
        int r = 0;
        for(auto i : nums){
            string s = to_string(i);
            int mn = 9, mx = 0;
            for(auto c : s){
                mx = max(mx, c - '0');
                mn = min (mn, c - '0');
            }
            r  =max(r, mx - mn);
        }

        for(auto i : nums){
            string s = to_string(i);
            int mn = 9, mx = 0;
            for(auto c : s){
                mx = max(mx, c - '0');
                mn = min(mn, c - '0');
            }
            if(mx - mn == r){
                sum += i;
            }
        }
        return sum;
    }
};