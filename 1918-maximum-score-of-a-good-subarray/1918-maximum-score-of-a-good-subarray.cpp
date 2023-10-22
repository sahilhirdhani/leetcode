class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int ans=nums[k];
        int mi=nums[k];
        int n = nums.size();

        while(i>0 || j<n-1){
            if(j==n-1){
                i--;
            }
            else if(i==0) {
                j++;
            }
            else if(nums[i-1]<nums[j+1]){
                j++;
            }
            else{
                i--;
            }
            mi=min(mi,min(nums[i],nums[j]));
            ans=max(ans,mi*(j-i+1));
        }
        return ans;

    }
};