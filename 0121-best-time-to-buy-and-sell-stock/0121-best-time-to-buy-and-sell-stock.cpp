class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int ans=0;
        for(auto x:prices){
            ans=max(ans,x-mini);
            mini=min(mini,x);
        }
        return ans;
    }
};