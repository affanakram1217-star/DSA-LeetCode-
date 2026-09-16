class Solution {
public:
    // bool checkDFS(int src, int des,vector<vector<int>>& adj,vector<bool>& vis){
    //     if(src==des){
    //         return true;
    //     }
    //     vis[src]=true;
    //     for(int v:adj[src]){
    //         if(!vis[v]){
    //             if(checkDFS(v,des,adj,vis)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        // return checkDFS(source,destination,adj,vis);

        //BFS 
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            if(node==destination){
                return true;
            }

            for(int v: adj[node]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }

        return false;
    }
};