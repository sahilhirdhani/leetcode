class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int slow=0,fast=0;
        while(true){
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(slow==fast) break;
        }
        fast =0;
        while(true){
            fast=nums[fast];
            slow=nums[slow];
            if(slow==fast) break;
        }
        return slow;
    }
};