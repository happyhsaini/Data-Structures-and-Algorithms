class Solution {
public:
    int compress(vector<char>& chars) {

        int write = 0;
        int i = 0;

        while (i < chars.size()) {

            char ch = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == ch) {
                count++;
                i++;
            }

            chars[write] = ch;
            write++;

            if (count > 1) {

                string num = to_string(count);

                for (char c : num) {
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
    }
};