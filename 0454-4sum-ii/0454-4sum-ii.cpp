class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int ans = 0;
        unordered_map<int ,int>mp1, mp2;
       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp1[nums1[i] + nums2[j]]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp2[nums3[i] + nums4[j]]++;
            }
        }

        for(auto &i : mp1){
            if(mp2.count(-i.first)){
                ans += i.second * mp2[-i.first];
            }
        }
        return ans;
    }
};