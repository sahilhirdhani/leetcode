class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(),nums.end());
        int si=nums.size();
        int ct=si/2;
        int c=1;
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                c++;
            }
            else{
                if(c>ct){
                    return nums[i];
                }
                c=1;
            }
        }
        return nums[nums.size()-1];
    }
};