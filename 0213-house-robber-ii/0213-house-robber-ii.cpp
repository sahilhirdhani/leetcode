class Solution {
public:
    int f(vector<int>& nums, int s, int n, vector<int>& dp){
        if(n<s){
            //return nums[s];
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int p=nums[n];
        if(n>=2){
            p+=f(nums,s,n-2,dp);
        }
        int np=f(nums,s,n-1,dp);
        return dp[n]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int a=f(nums,1,n-1,dp1);
        int b=f(nums,0,n-2,dp2);
        return max(a,b);
    }
};