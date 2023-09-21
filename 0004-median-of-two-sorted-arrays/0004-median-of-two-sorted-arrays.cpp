class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<double> nums;
        int i=0,j=0;
        int si1=nums1.size(),si2=nums2.size();
        int t=si1+si2;
        while(i<si1 && j<si2 && nums.size()<(t/2)+1 ){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<si1 && nums.size()<(t/2)+1){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<si2 && nums.size()<(t/2)+1){
            nums.push_back(nums2[j]);
            j++;
        }
        if(t%2==0){
            return (nums[nums.size()-2]+nums[nums.size()-1])/2;
        }
        else{
            return nums[nums.size()-1];
        }
    }
};