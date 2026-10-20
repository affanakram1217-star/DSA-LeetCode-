// class Solution {
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n=graph.size();
//         if(n==0 || n==1){
//             return 0;
//         }

//         queue<pair<int,int>> q; //stores node,bitmask
//         set<pair<int,int>> visited; 

//         for(int i=0;i<n;i++){
//             int maskValue=(1<<i); 
//             q.push({i,maskValue});
//             visited.insert({i,maskValue});
//         }

//         int allVisitedState=(1<<n)-1;

//         int path=0;
//         while(!q.empty()){
//             int size=q.size();
//             path++;

//             while(size--){
//                 pair<int,int> curr=q.front();
//                 q.pop();

//                 int currNode=curr.first;
//                 int currMask=curr.second;

//                 for(int& adj:graph[currNode]){
//                     int nextMask=currMask | (1<<adj);

//                     if(nextMask==allVisitedState){
//                         return path;
//                     }

//                     if(visited.find({adj,nextMask})==visited.end()){
//                         q.push({adj,nextMask});
//                         visited.insert({adj,nextMask});
//                     }
//                 }
//             }

//         }

//         return -1;
//     }
// };

//Approach 2
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 1) return 0;

        int allVisitedState = (1 << n) - 1;
        queue<pair<int, int>> q; // {currNode, currMask}
        
        // visited[node][mask] replaces set
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            q.push({i, maskValue});
            visited[i][maskValue] = true;
        }

        int path = 0;
        while (!q.empty()) {
            int size = q.size();
            path++;

            while (size--) {
                auto [currNode, currMask] = q.front(); //unpack automatically
                q.pop();

                for (int adj : graph[currNode]) {
                    int nextMask = currMask | (1 << adj);

                    if (nextMask == allVisitedState) {
                        return path;
                    }

                    if (!visited[adj][nextMask]) {
                        visited[adj][nextMask] = true;
                        q.push({adj, nextMask});
                    }
                }
            }
        }

        return -1;
    }
};