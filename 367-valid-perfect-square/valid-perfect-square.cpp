
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ans = mid * mid;

            if (ans == num) {
                return true;
            } else if (ans < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
