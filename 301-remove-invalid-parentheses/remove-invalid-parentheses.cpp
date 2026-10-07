class Solution {
public:
    
    bool isValid(string s) {
        
        int count = 0;
        
        for (char c : s) {
            
            if (c == '(')
                count++;
            
            else if (c == ')') {
                
                count--;
                
                if (count < 0)
                    return false;
            }
        }
        
        return count == 0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> ans;
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size--) {
                
                string curr = q.front();
                q.pop();
                
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }
                
                // If we already found valid strings at this level,
                // don't remove more parentheses.
                if (found)
                    continue;
                
                for (int i = 0; i < curr.length(); i++) {
                    
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;
                    
                    string next = curr.substr(0, i) + curr.substr(i + 1);
                    
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            
            if (found)
                break;
        }
        
        return ans;
    }
};