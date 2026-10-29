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

    int solve(TreeNode* root){
        if(!root) return 2;

        int left = solve(root->left);
        int right = solve(root->right);

        if(left == 0 || right == 0){
            camera++;
            return 1;
        }

        if(left == 1 || right == 1) {
            return 2;
        }

        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        camera = 0;
        if(solve(root) == 0){
            camera++;
        }

        return camera;
    }
};