class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        while(left<right){
            int weight=right-left;
            int hit=min(height[left],height[right]);
            ans=max(ans,weight*hit);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};