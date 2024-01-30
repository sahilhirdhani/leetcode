class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int j=1;
        while(q.size()){
            int si=q.size();
            vector<int> temp(si);
            for(int i=0;i<si;i++){
                TreeNode* t=q.front();
                q.pop();
                if(j%2==0){
                    temp[si-1-i]=t->val;
                }
                else{
                    temp[i]=t->val;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            j++;
            ans.push_back(temp);
        }
        return ans;
    }
};