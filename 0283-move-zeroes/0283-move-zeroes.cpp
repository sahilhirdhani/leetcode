class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        int a=ans.size();
        for(int i=0;i<a;i++){
            nums[i]=ans[i];
        }
        for(int i=a;i<n;i++){
            nums[i]=0;
        }
    }
};