class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int lo=0;
        int size=nums.size()-1;
        int high=size;
        int mid;
        vector<int> ans = {-1,-1};
        while(lo<=high){
            mid=lo+(high-lo)/2;
            if(nums[mid]==t){
                ans[0]=mid;
                high=mid-1;
            }
            else if(nums[mid]<t){
                lo=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        lo=0;
        high=size;
        while(lo<=high){
            mid=(high+lo)/2;
            if(nums[mid]==t){
                ans[1]=mid;
                lo=mid+1;
            }
            else if(nums[mid]<t){
                lo=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};