class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int length=nums1.size()+nums2.size();
      vector<int> arr;
      int i=0,j=0;
      while(i<length){
        if(i<nums1.size()){
            arr.push_back(nums1[i]);
        }else{
            arr.push_back(nums2[j]);
            j++;
        }
        i++;
      }
      sort(arr.begin(),arr.end());
      if(length%2==0){
        int mid=length/2;
        double s=(arr[mid-1]+arr[mid])/2.0;
        return s;
      }else{
        int mid=(length-1)/2;
        return arr[mid];
      }
      return 0;
    }
};