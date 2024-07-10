class Solution {
public:
    int fn(vector<int>& nums, int id, int pid, int &size, vector<vector<int>> &dp){
        if(id==size-1){
            if(pid==-1 || nums[id]>nums[pid]){
                return dp[id][pid+1] = 1;
            }
            return dp[id][pid+1] = 0;
        }
        if(dp[id][pid+1]!=-1){
            return dp[id][pid+1];
        }
        int p = 0;
        if(pid==-1 || nums[id]>nums[pid]){
            p=1+fn(nums,id+1,id,size,dp);
        }
        int np=fn(nums,id+1,pid,size,dp);
        return dp[id][pid+1] = max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

        int si=nums.size();
        vector<vector<int>> dp(si+1,vector<int>(si+2,-1));
        return fn(nums,0,-1,si,dp);
    }
};