class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<int> even;
        vector<int> odd;
        int si=nums.size();
        for(int i=1;i<si;i+=2){
            odd.push_back(nums[i]);
        }
        for(int i=0;i<si;i+=2){
            even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        for(int i=0;i<si;i+=2){
            nums[i]=even[i/2];
        }
        for(int i=1;i<si;i+=2){
            nums[i]=odd[i/2];
        }
        return nums;
    }
};