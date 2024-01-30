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
    int maxlev=0;
    void func(TreeNode* root, int lev, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(maxlev<lev){
            ans.push_back(root->val);
            maxlev=lev;
        }
        func(root->right,lev+1,ans);
        func(root->left,lev+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        func(root,1,ans);
        return ans;
    }
};