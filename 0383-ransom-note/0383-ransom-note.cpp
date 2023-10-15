class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mr;
        unordered_map<char,int> mm;
        for(auto x:r){
            mr[x]++;
        }
        for(auto x:m){
            mm[x]++;
        }
        for(auto x:r){
            try{
                if(mr[x]>mm[x]){
                    return false;
                }
            }
            catch(exception e){
                return false;
            }
        }
        return true;
    }
};