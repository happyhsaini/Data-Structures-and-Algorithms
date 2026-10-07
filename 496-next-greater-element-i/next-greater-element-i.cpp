class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mp;
        
        // Find next greater element for every element in nums2
        for (int num : nums2) {
            
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            
            st.push(num);
        }
        
        // Elements remaining in stack have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        
        // Build answer for nums1
        vector<int> ans;
        
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        
        return ans;
    }
};