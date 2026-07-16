class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;

        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                long long need = target - 1LL * nums[i] - 1LL * nums[j];
                int low = j + 1;
                int high = n - 1;
                while(low < high){
                    if(nums[low] + nums[high] < need){
                        low++;
                    }
                    else if(nums[low] + nums[high] > need){
                        high--;
                    }
                    else{
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }

        for(auto &i : st){
            ans.push_back(i);
        }
        return ans;

    }
};