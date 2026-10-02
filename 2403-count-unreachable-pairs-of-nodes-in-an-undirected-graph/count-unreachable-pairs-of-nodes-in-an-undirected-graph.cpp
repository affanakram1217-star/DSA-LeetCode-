class Solution {
public:
    void dfs(int curr, unordered_map<int,vector<int>> &adj, vector<bool>& vis, long long &Size){
        vis[curr]=true;
        Size++;

        for(int &v: adj[curr]){
            if(!vis[v]){
                dfs(v,adj,vis,Size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long remSize=n;
        long long result=0;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long Size=0;
                dfs(i,adj,vis,Size);
                result+=(Size)*(remSize-Size);
                remSize-=Size;
            }
        }
        return result;
    }
};