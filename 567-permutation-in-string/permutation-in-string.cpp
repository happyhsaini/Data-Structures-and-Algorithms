class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (char c : s1) {
            a[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.length(); right++) {

            b[s2[right] - 'a']++;

            if (right - left + 1 > s1.length()) {
                b[s2[left] - 'a']--;
                left++;
            }

            if (a == b)
                return true;
        }

        return false;
    }
};