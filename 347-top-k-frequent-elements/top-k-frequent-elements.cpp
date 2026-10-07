class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency
        unordered_map<int, int> freq;
        
        for (int x : nums) {
            freq[x]++;
        }
        
        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);
        
        for (auto it : freq) {
            int num = it.first;
            int count = it.second;
            
            bucket[count].push_back(num);
        }
        
        // Step 3: Get top k frequent elements
        vector<int> ans;
        
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            
            for (int num : bucket[i]) {
                ans.push_back(num);
                
                if (ans.size() == k)
                    break;
            }
        }
        
        return ans;
    }
};