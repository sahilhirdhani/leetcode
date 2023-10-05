class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int si=nums.size();
        int ct=si/3;
        int c=1;
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                c++;
            }
            else{
                if(c>ct){
                    ans.push_back(nums[i]);
                }
                c=1;
            }
        }
        if(c>ct){
            ans.push_back(nums[nums.size()-1]);
        }
        return ans;
    }
};