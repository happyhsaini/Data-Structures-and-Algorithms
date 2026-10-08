class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){

            if(nums[left]<nums[right]){
                right--;
            }else{
                left++;
            }
        }
        return nums[right];
    }
};