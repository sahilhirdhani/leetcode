class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        int si=pref.size();
        if(si==0 || si==1){
            return pref;
        }
        for(int i=si-1;i>=1;i--){
            pref[i]=pref[i]^pref[i-1];
        }
        return pref;

    }
};