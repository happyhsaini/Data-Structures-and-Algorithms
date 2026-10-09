class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int r=nums.size()-1;
            while(j<r){
                int sum=nums[i]+nums[j]+nums[r];
                if(sum==0){
                    vector<int> temp={nums[i],nums[j],nums[r]};
                    ans.push_back(temp);
                    j++;
                    r--;
                    while(j<r && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }else if(sum>0){
                    r--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};