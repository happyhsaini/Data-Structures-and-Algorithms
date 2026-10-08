class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                // If depth > 0, this is NOT an outermost '('
                if (depth > 0)
                    ans += c;

                depth++;
            }
            else {
                depth--;

                // If depth > 0, this is NOT an outermost ')'
                if (depth > 0)
                    ans += c;
            }
        }

        return ans;
    }
};