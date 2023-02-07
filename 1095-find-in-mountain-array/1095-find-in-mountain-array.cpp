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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s=0;
        int e=mountainArr.length()-1;
        int mid=(s+e)/2;
        int ans=-1;
        while(s<e){
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                s = mid + 1;
            } 
            else{
               e = mid; 
            } 
            mid=(s+e)/2;
        }
        int peak=s;
        s=0;
        e=peak;
        bool left=false;
        while(s<=e){
            mid=(s+e)/2;
            if(mountainArr.get(mid)==target){
                left=true;
                break;
            }
            else if(mountainArr.get(mid) < target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(left){
            return mid;
        }
        s= peak+1;
        e=mountainArr.length() - 1;
        bool right=false;
        while(s<=e){
            mid=(s+e)/2;
            if(mountainArr.get(mid)==target){
                right=true;
                break;
            }
            else if(target<mountainArr.get(mid)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }  
        }
        if(right){
            return mid;
        }
        return -1;
    }
};