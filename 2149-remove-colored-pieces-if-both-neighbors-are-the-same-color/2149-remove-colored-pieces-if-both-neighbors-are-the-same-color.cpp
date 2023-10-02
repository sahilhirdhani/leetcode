class Solution {
public:
    bool winnerOfGame(string c) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int a=0;
        int b=0;
        for(int i=1;i<c.size()-1;i++){
            if(c[i-1]==c[i] && c[i]==c[i+1]){
                if(c[i]=='A'){
                    a++;
                }
                else{
                    b++;
                }
            }
        }
        return a>b;
    }
};