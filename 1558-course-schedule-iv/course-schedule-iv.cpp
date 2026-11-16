class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto& edge: prerequisites){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        unordered_map<int,unordered_set<int>> topoWithPrereqs;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto& v: adj[u]){
                // Add node and prerequisite of node to the prerequisites of adj
                topoWithPrereqs[v].insert(u);
                for(auto& preq: topoWithPrereqs[u]){
                    topoWithPrereqs[v].insert(preq);
                }

                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        int size=queries.size();
        vector<bool> result(size,false);

        for(int i=0;i<size;i++){
            int src=queries[i][0];
            int dest=queries[i][1];

            bool isReachable=topoWithPrereqs[dest].contains(src);
            result[i]=isReachable;
        }

        return result;
    }
};