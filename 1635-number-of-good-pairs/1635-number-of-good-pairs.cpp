class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        int sum=0;
        for(auto x:m){
            if(x.second>1){
                sum+=(((x.second)*(x.second-1))/2);
            }
        }
        return sum;
    }
};