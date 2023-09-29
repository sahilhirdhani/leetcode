class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int si=nums.size();
        int i=0;
        if(nums[0]<nums[si-1]){
            while(i<si-1){
                if(nums[i]>nums[i+1]){
                    return false;
                }
                i++;
            }
            return true;
        }
        else if(nums[0]>nums[si-1]){
            while(i<si-1){
                if(nums[i]<nums[i+1]){
                    return false;
                }
                i++;
            }
            return true;
        }
        else{
            while(i<si-1){
                if(nums[i]!=nums[i+1]){
                    return false;
                }
                i++;
            }
            return true;
        }
    }
};