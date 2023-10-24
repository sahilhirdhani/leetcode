class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(root==NULL){
                return root;
            }
            else if(val==root->val){
                return root;
            }
            else if(root->val>val){
                root=root->left;
            }
            else if(root->val<val){
                root=root->right;
            }
        }
        
        return root;
    }
};