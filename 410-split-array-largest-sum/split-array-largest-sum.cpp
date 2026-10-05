class Solution {
public:
    int Countsum(vector<int>& nums,int sum){
        int element=1;
        long long largest=0;
        for(int i=0;i<nums.size();i++){
            if(largest+nums[i]<=sum){
                largest+=nums[i];
            }else{
                element+=1;
                largest=nums[i];
            }
        }
        return element;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<=right){
            int mid=(left+right)/2;
            int largestSum=Countsum(nums,mid);
            if(largestSum > k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
};