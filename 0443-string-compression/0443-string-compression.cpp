class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        int id=0;
        vector<char> cha;
        for(int i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                cha.push_back(chars[id]);
                if(count>1){
                    string ct=to_string(count);
                    for(char x:ct){
                        cha.push_back(x);
                    }
                }
                count=1;
                id=i+1;
            }
        }
        cha.push_back(chars[id]);
        if(count>1){
            string ct=to_string(count);
            for(char x:ct){
                 cha.push_back(x);
            }
        }
        for(int i=0;i<cha.size();i++){
            chars[i]=cha[i];
        }
        return cha.size();
    }
};