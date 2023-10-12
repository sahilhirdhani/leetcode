/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int low=0;
        int high=arr.length();
        int mid;
        int ans1=-1;
        int ans2=-1;

        int peak;
        while(low<high){
            mid=(high+low)/2;
            if(arr.get(mid)>arr.get(mid+1) && arr.get(mid)>arr.get(mid-1)){
                peak=mid;
                break;
            }
            else if(arr.get(mid)<arr.get(mid+1)){
                low=mid;
            }
            else if(arr.get(mid)<arr.get(mid-1)){
                high=mid;
            }
        }
        if(arr.get(peak) < target){
            return -1;
        }
        else if(arr.get(peak) == target){
            return peak;
        }

        low=0;
        high=peak-1;
        
        while(low<=high){
            mid=(high+low)/2;
            if(arr.get(mid) == target){
                ans1 = mid;
                return mid;
            }
            else if(arr.get(mid)<target){
                low=mid+1;
            }
            else if(arr.get(mid)>target){
                high=mid-1;
            }
        }

        low=peak+1;
        high=arr.length()-1;
        
        while(low <= high){
            mid=(high+low)/2;
            if(arr.get(mid) == target){
                return mid;
                
            }
            else if(arr.get(mid)<target){
                high=mid-1;
            }
            else if(arr.get(mid)>target){
                low=mid+1;
            }
        }
        return -1;
    }
};