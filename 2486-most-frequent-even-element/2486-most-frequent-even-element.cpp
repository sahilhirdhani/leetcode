class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
        }
        int ma=-1,ans=-1;
        for(auto x:m){
            if(ma==x.second){
                ans=min(ans,x.first);
            }
            else if(ma<x.second){
                ma=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};