class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        int s1=0;
        int t1=0;
        for(int i=0;i<s.size();i++){
            s1+=s[i];
            t1+=t[i];
        }
        t1+=t[t.size()-1];
        char ans=t1-s1;
        return ans;
    }
};