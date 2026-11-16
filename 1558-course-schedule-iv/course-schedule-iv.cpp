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

    void preProcess(unordered_map<int,vector<int>>&adj, int n,vector<vector<bool>>& isPrerequisite){

        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(u!=v){
                    vector<bool> vis(n,false);
                    isPrerequisite[u][v]=dfs(u,v,adj,vis);
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge: prerequisites){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }

        vector<vector<bool>> isPrerequisite(numCourses,vector<bool>(numCourses,false));
        preProcess(adj,numCourses,isPrerequisite);

        int q=queries.size();
        vector<bool> result(q,false);

        for(int i=0;i<q;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            
            result[i]=isPrerequisite[src][dest];
        }

        return result;
    }
};