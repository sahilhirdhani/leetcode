class Solution {
public:
    void swap(int& a,int& b){
        int c=a;
        a=b;
        b=c;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int b=0;
        int e=nums.size()-1;
        while(b<e){
            if(nums[e]%2==0 && nums[b]%2!=0){
                swap(nums[e],nums[b]);
                e--;
                b++;
            }
            if(nums[b]%2==0){
                b++;
            }
            if(nums[e]%2!=0){
                e--;
            }
        }
        return nums;
    }
};