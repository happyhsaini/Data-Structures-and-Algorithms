class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int x=-1,y=-1;
        vector<int> ans(2);
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                y=mid;
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        left=0;
        right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                x=mid;
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        ans[0]=y;
        ans[1]=x;
        return ans;
    }
};