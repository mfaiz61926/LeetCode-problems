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
    int camera;
    
    int dfs(TreeNode* root){
        if(!root) return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 0 || right == 0){
            camera++;
            return 1;
        }
        else if(left == 1 || right == 1) return 2;

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        camera = 0;
        if(dfs(root) == 0) camera++;
        return camera;
    }
};