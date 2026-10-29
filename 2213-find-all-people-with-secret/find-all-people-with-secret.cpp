class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq; //I need the ones first having min time
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        vector<bool> visited(n, false);
        
        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            
            if(visited[person] == true) {
                continue;
            }
            visited[person] = true;
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && !visited[nextPerson]) {
                    pq.push({t, nextPerson});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};