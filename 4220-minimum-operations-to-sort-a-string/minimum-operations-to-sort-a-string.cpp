#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        // 0 operations: Already sorted
        if (s == t) return 0;

        int n = s.size();

        // Impossible: Can only sort length-1 substrings, which does nothing
        if (n == 2) return -1;

        // 1 operation: If the first or last character is already in its sorted place,
        // we can just sort the remaining n-1 characters in 1 move.
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        // 2 operations: We can sort in 2 moves if:
        // - The minimum character (t[0]) exists anywhere in s[0 ... n-2], OR
        // - The maximum character (t[n-1]) exists anywhere in s[1 ... n-1]
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == t[0]) return 2;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == t[n - 1]) return 2;
        }

        // 3 operations: s[0] is the unique maximum and s[n-1] is the unique minimum
        return 3;
    }
};