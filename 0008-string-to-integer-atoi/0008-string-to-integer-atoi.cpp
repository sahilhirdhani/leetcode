class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool negative=false;
        int size=s.size();
        int id=0;
        for(;id<size;id++){
            if(s[id]==' '){
                continue;
            }
            else if(s[id]=='-'){
                negative=true;
                id++;
                break;
            }
            else if(s[id]=='+'){
                id++;
                break;
            }
            else if(s[id]>='0' && s[id]<='9'){
                break;
            }
            else{
                return ans;
            }
        }
        for(;id<size;id++){
            if(!(s[id]>='0' && s[id]<='9')){
                break;
            }

            ans*=10;

            if(ans+(s[id]-'0')>=2147483647){
                if(negative && ans+s[id]-'0'==INT_MAX){
                    return -INT_MAX;
                }
                ans=INT_MAX;
                break;

            }
            ans+=(s[id]-'0');
        }
        if(negative){
            if(ans==INT_MAX){
                ans+=1;
            }
            ans=-ans;
        }
        return ans;
    }
};