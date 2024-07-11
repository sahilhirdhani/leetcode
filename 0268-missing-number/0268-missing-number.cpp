class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        n=n*(n+1);
        n=n/2;
        for(auto x:nums){
            n-=x;
        }
        return n;
    }
};