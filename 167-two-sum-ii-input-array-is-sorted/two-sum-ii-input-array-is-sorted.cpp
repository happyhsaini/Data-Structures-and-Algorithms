class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<numbers.size();i++){
            int need=target-numbers[i];
            if(mp.find(need)!=mp.end()){
                return {mp[need]+1,i+1};
            }
            mp[numbers[i]]=i;
        }
        return {};
    }
};