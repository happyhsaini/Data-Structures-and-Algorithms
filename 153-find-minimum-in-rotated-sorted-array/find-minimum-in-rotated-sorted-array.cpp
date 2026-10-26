class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,hight=nums.size()-1;
        while(left<hight){
            int mid=(left+hight)/2;
            if(nums[mid]>nums[hight]){
                left=mid+1;
            }else{
                hight=mid;
            }
        }
        return nums[left];
    }
};