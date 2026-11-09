#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> counts(k, 0);
        set<int> free_servers;
        
        // Initially, all servers are free
        for (int i = 0; i < k; ++i) {
            free_servers.insert(i);
        }
        
        // Min-heap to store {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long time = arrival[i];
            long long duration = load[i];
            
            // 1. Release servers that have finished processing by the current request's arrival time
            while (!busy_servers.empty() && busy_servers.top().first <= time) {
                free_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            // 2. If no servers are free, the request is dropped
            if (free_servers.empty()) {
                continue;
            }
            
            // 3. Find the next available server starting from (i % k)
            int target = i % k;
            auto it = free_servers.lower_bound(target);
            
            // 4. Wrap around to the beginning if no server is available at or after 'target'
            if (it == free_servers.end()) {
                it = free_servers.begin();
            }
            
            // 5. Assign the request
            int server_id = *it;
            free_servers.erase(it);
            counts[server_id]++;
            busy_servers.push({time + duration, server_id});
        }
        
        // Find the maximum requests handled by any server
        int max_requests = *max_element(counts.begin(), counts.end());
        
        vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_requests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};