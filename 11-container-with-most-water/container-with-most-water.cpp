class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1;
        while(left<right){
            int weight=right-left;
            int h=min(height[left],height[right]);
            ans=max(ans,weight*h);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};