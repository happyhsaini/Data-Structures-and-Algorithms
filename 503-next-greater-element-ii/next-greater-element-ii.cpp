class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n, -1);
        stack<int> st;
        
        for (int i = 0; i < 2 * n; i++) {
            
            int index = i % n;
            
            while (!st.empty() && nums[st.top()] < nums[index]) {
                ans[st.top()] = nums[index];
                st.pop();
            }
            
            // Push only during the first traversal
            if (i < n) {
                st.push(index);
            }
        }
        
        return ans;
    }
};