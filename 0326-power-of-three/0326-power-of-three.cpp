class Solution {
public:
    string s="";
    void fun(int n){
        if(n==0){
            return;
        }
        fun(n/3);
        s+=to_string(n%3);
    }
    bool check(){
        for(int i=1;i<s.size();i++){
            if(s[i]!='0'){
                return false;
            }
        }
        return true;
    }
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        fun(n);
        if(s[0]=='1' && check()){
            return true;
        }
        return false;
    }
};