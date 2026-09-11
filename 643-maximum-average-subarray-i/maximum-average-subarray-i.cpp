class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0,right=k-1,sum=0;
        for(int i=left;i<=right;i++){
            sum=sum+nums[i];
        }
        double maxAverage=(double)sum/k;
        while(right<nums.size()-1){
            sum=sum-nums[left];
            left++;
            right++;
            sum=sum+nums[right];
            double temp=(double)sum/k;
            maxAverage=max(maxAverage,temp);
        }
        return maxAverage;
    }
};