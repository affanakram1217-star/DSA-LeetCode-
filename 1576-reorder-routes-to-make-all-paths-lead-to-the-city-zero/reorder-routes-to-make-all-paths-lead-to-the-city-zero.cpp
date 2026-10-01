class Solution {
public:
    // int count=0;
    // void dfs(int node, int parent, unordered_map<int,vector<pair<int,int>>>& adj){
    //     for(auto& p:adj[node]){
    //         int v=p.first;//neighbour node
    //         if(v==parent) continue;
    //         int check=p.second;

    //         if(check==1){
    //             count++;
    //         }

    //         dfs(v,node,adj);
    //     }
    // }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto& vec: connections){
            int u=vec[0];
            int v=vec[1];
            
            adj[u].push_back({v,1});//real
            adj[v].push_back({u,0});//fake edge
        }

        // dfs(0,-1,adj);

        // return count;

        //BFS
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int ans=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto& p:adj[u]){
                int v=p.first;
                if(!visited[v]){
                    int check=p.second;
                    visited[v]=true;

                    if(check==1){
                        ans++;
                    }
                    q.push(v);
                }
            }
        }
        return ans;
    }
};