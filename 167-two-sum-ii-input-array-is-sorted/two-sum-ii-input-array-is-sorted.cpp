class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int current_sum = numbers[left] + numbers[right];

            if (current_sum == target) {
                return {left + 1, right + 1}; // 1-based indexing
            } else if (current_sum < target) {
                left++; // Sum chhota hai, toh left ko aage badhao
            } else {
                right--; // Sum bada hai, toh right ko peechhe lao
            }
        }
        return {};
    }
};