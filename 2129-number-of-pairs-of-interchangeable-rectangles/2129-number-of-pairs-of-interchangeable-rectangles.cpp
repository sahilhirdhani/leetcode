class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<double,int> m;
        for(const auto& x:rect){
            double t=static_cast<double>(x[0])/x[1];
            m[t]++;
        }
        long long ans=0;
        for(const auto& x:m){
            long long cnt=x.second;
            if(cnt>1){
                ans+=((cnt*(cnt-1))/2);
            }
        }
        return ans;
    }
};