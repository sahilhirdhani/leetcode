class Solution {
public:
    void func(string& tape, string& ans){
        for(int i=tape.size()-1;i>=0;i--){
            ans+=tape[i];
        }
        tape="";
    }
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        string tape="";
        string ans="";
        int bol=1;
        for(auto x:s){
            if(x==' '){
                if(bol!=1){
                    ans+=x;
                }
                func(tape,ans);
                bol=0;
            }
            else{
                tape+=x;
            }
        }
        if(bol!=1){
            ans+=' ';
        }
        func(tape,ans);
        return ans;
    }
};