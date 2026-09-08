class Solution {
public:
//TARJAN"S ALGORITHM=DFS+SOME EXTRA VARIABLES
    int time;
    vector<int> dt,l;
    void dfs(int u, int parU, vector<vector<int>> &adj, vector<vector<int>>& bridges){
        dt[u]=l[u]=++time;

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(dt[v]==-1){//can also use a vis bool vector like !vis[u]
                dfs(v,u,adj,bridges);
                l[u]=min(l[u],l[v]);

                if(l[v]>dt[u]){
                    bridges.push_back({u,v});
                }
            }else if(v!=parU){
                l[u]=min(l[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //adj list
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dt.assign(n,-1);//assigning -1 ensures that we dont need vis vector , if only resize then vis vector req
        l.resize(n);
        vector<vector<int>> bridges;

        for(int i=0;i<n;i++){
            if(dt[i]==-1){
                dfs(i,-1,adj,bridges);
            }
        }

        return bridges;
    }
};