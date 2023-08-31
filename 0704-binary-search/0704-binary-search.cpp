class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return -1;
    }
};