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
    int level(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(level(root->right),level(root->left))+1;
    }
    void print(TreeNode* root, int l, vector<int>& ans, int& h){
        if(root==NULL){
            return;
        }
        else{
            ans[h-l]=max(ans[h-l],root->val);
            print(root->left,l-1,ans,h);
            print(root->right,l-1,ans,h);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.tie(NULL);
        cin.tie(0);
        cout.tie(0);
        int h=level(root);
        vector<int> ans(h,INT_MIN);
        print(root,h,ans,h);
        return ans;
    }
};