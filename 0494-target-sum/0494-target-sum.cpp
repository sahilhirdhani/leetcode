class Solution {
public:
    int f(vector<int>& nums, int sum, int id,vector<vector<int>>& dp){
        if(id==0){
            if(sum==nums[id] && sum==0){
                return 2;
            }
            if(sum==nums[id] || sum==0){
                return 1;
            }
            return 0;
        }
        if(dp[id][sum]!=-1){
            return dp[id][sum];
        }
        int a = f(nums,sum,id-1,dp);
        int b=0;
        if(sum>=nums[id]){
            b = f(nums,sum-nums[id],id-1,dp);
        }
        return dp[id][sum]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum=0;
        for(auto x:nums){
            totsum+=x;
        }
        int a=totsum-target;
        if(a%2 || a<0){
            return 0;
        }
        a/=2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(a+1,-1));
        return f(nums,a,n-1,dp);
    }
};