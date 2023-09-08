class Solution {
public:
    vector<int> getRow(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<int> ans;
        
        ans.push_back(1);
        
        if(n == 0) {
            return ans;
        }

        for(int i=1;i<=n/2;i++){
            size_t num=1;
            for(int j=0;j<i;j++){
                num=num*(n-j)/(j+1);
            }
            ans.push_back(num);
        }
        
        int si=ans.size();
        if(n%2==0){
            si--;
        }
        
        for(int i=si-1;i>=0;i--){
            ans.push_back(ans[i]);
        }
        return ans;
    }
};