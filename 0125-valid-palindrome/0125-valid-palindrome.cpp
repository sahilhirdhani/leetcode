class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if((s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122 || s[j]>=48 && s[j]<=57) && (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i]>=48 && s[i]<=57)){
                if(s[j] >= 65 && s[j] <= 90){
                    s[j]+=32;
                }
                if(s[i] >= 65 && s[i] <= 90){
                    s[i]+=32;
                }
                if(s[i]!=s[j]){
                    return false;
                }
                if(s[i]==s[j]){
                    i++;
                    j--;
                }
            }
            else{
                if(!(s[j] >= 65 && s[j] <= 90 || s[j] >= 97 && s[j] <= 122 || s[j]>=48 && s[j]<=57)){
                    j--;
                }
                if(!(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i]>=48 && s[i]<=57)){
                    i++;
                }
            }
        }
        return true;
    }
};