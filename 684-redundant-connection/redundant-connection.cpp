class Solution {
public:
    bool dfs(int u, int v, unordered_map<int,vector<int>> &adj,vector<bool> &vis){
        vis[u]=true;

        if(u==v){
            return true;
        }

        for(int&ngbr : adj[u]){
            if(!vis[ngbr]){
                if(dfs(ngbr,v,adj,vis)){
                    return true;
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            vector<bool> vis(n,false);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,adj,vis)){
                return {u,v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};