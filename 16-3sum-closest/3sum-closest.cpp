class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int closest=nums[0]+nums[1]+nums[2];

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j=i+1;
            int r=nums.size()-1;

            while(j<r){
                int sum=nums[i]+nums[j]+nums[r];

                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }

                if(sum<target){
                    j++;
                }else{
                    r--;
                }
            }
        }

        return closest;
    }
};