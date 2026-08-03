/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>mp;
    int f(TreeNode* root){
        if(!root) return 0;
        int left = f(root->left);
        int right = f(root->right);

        int sum = left + right + root->val;
        mp[sum]++;

        return  sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mp.clear();
        f(root);
        vector<int>ans;
        int mx = 0;
        for(auto &i : mp){
            mx = max(mx, i.second);
        }

        for(auto &i : mp){
            if(i.second == mx) ans.push_back(i.first);
        }

        return ans;
    }
};