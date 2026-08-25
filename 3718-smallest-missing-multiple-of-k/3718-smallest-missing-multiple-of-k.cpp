class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(auto &i : nums) st.insert(i);

        long long mul = k;
        while(true){
            if(st.find(mul) == st.end()) return mul;
            mul += k;
        }
    }
};