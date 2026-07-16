class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int ans = 0;
        unordered_map<int ,int>mp1;
       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp1[nums1[i] + nums2[j]]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = nums3[i] + nums4[j];
                if(mp1.count(-x)) ans += mp1[-x]; 
            }
        }

        return ans;
    }
};