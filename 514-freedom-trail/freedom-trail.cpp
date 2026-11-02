
class Solution {
public:
    int countSteps(int ringIdx, int i, int n) {
        int dist = abs(i - ringIdx);
        int wrapAround = n - dist;

        return min(dist, wrapAround);
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();

        // Map each character to its positions in the ring
        unordered_map<char, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[ring[i]].push_back(i);
        }

        // {rotationCost, ringIdx, keyIdx}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, 0, 0});

        set<pair<int, int>> visited;

        while (!pq.empty()) {
            auto vec = pq.top();
            pq.pop();

            int totalSteps = vec[0];
            int ringIdx = vec[1];
            int keyIdx = vec[2];

            // All characters have been processed
            if (keyIdx == m) {
                return totalSteps + m;
            }

            if (visited.count({ringIdx, keyIdx})) {
                continue;
            }

            visited.insert({ringIdx, keyIdx});

            char currChar = key[keyIdx];

            for (int nextIdx : adj[currChar]) {
                int steps = countSteps(ringIdx, nextIdx, n);

                pq.push({
                    totalSteps + steps,
                    nextIdx,
                    keyIdx + 1
                });
            }
        }

        return -1;
    }
};
