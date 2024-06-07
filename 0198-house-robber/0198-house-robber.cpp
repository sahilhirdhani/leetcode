class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp){
        if(n==0){
            return nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int p=nums[n];
        if(n>=2){
            p+=f(nums,n-2,dp);
        }
        int np=f(nums,n-1,dp);
        return dp[n]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(nums,n-1,dp);
    }
};