class Solution {
public:
    bool dfs(int src, int dest,unordered_map<int,vector<int>>& adj,vector<bool>& vis){
        vis[src]=true;

        if(src==dest){
            return true;
        }

        bool reachable=false;
        for(int& v: adj[src]){
            if(!vis[v]){
                reachable=reachable||dfs(v,dest,adj,vis);
            }
        }

        return reachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: prerequisites){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }

        int q=queries.size();
        vector<bool> result(q,false);

        for(int i=0;i<q;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            
            vector<bool> vis(numCourses,false);
            result[i]=dfs(src,dest,adj,vis);
        }

        return result;
    }
};