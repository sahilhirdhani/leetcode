class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        int o=0;
        int ans=0;
        for(auto x:m){
            if(x.second%2==0){
                ans+=x.second;
            }
            else{
                o=1;
                ans+=x.second-1;
            }
        }
        return o==1 ? ans+1 : ans;
    }
};