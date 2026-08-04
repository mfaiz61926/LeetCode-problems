class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(), nums.end());
        set<int>st;
        for(auto &i : nums) st.insert(i);
        for(int i = nums[0]; i <= nums[n - 1]; i++){
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};