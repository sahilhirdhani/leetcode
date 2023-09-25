class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s=countAndSay(n-1);
        string res="";
        int count=1;
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1 && s[i]==s[i+1]){
                count++;
            }
            else{
                res += to_string(count)+s[i];
                count=1;
            }
        }
        return res;
    }
};