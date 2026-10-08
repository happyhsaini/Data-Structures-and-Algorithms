class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }else{
                right=mid;
            }
            // if(nums[left]<nums[right]){
            //     right--;
            // }else{
            //     left++;
            // }
        }
        return nums[left];
    }
};