class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0,right=arr.size()-1;
        int ans;
        while(left<right){
            if(arr[left]<=arr[right]){
                left++;
            }else{
                right--;
            }
        }
        if(arr[left]<arr[right]){
            ans=left;
        }else{
            ans=right;
        }
        return ans;
    }
};