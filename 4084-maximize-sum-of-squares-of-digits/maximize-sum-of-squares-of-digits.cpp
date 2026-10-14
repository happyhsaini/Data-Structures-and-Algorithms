
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (num > 0) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
            num--;
        }

        return ans;
    }
};
