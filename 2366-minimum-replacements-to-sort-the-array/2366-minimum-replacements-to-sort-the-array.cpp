class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long ans=0;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) continue;
            long replacements=(long)(nums[i]+nums[i+1]-1)/(long)nums[i+1];
            ans+=replacements-1;
            nums[i]/=(int)replacements;
        }
        return ans;
    }
};