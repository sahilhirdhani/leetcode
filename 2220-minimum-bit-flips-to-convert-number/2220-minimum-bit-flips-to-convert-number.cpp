class Solution {
public:
    int minBitFlips(int start, int goal) {
        start=start^goal;
        int count=0;
        for(int i=0;i<30;i++){
            if(start & (1<<i)){
                count++;
            }
        }
        return count;
    }
};