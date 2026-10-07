class Solution {
public:
    int calculate(string s) {
        
        stack<long long> st;
        
        long long result = 0;
        long long number = 0;
        long long sign = 1;
        
        for (int i = 0; i < s.length(); i++) {
            
            if (isdigit(s[i])) {
                
                number = 0;
                
                while (i < s.length() && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                
                i--;
                
                result += sign * number;
            }
            
            else if (s[i] == '+') {
                sign = 1;
            }
            
            else if (s[i] == '-') {
                sign = -1;
            }
            
            else if (s[i] == '(') {
                
                st.push(result);
                st.push(sign);
                
                result = 0;
                sign = 1;
            }
            
            else if (s[i] == ')') {
                
                long long prevSign = st.top();
                st.pop();
                
                long long prevResult = st.top();
                st.pop();
                
                result = prevResult + prevSign * result;
            }
        }
        
        return (int)result;
    }
};