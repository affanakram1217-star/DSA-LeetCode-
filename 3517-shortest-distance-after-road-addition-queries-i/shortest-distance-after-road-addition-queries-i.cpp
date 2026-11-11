class Solution {
public:
    int bfs(unordered_map<int,vector<int>> &adj, int n){
        queue<int> q;
        q.push(0);
        int level=0;
        vector<bool> vis(n,false);
        vis[0]=true;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();

                if(node==n-1){
                    return level;
                }

                for(int& nbr: adj[node]){
                    if(!vis[nbr]){
                        vis[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            level++;
        }

        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<=n-2;i++){
            adj[i].push_back(i+1);
        }

        vector<int> result;

        for(auto& query: queries){
            int u=query[0];
            int v=query[1];

            adj[u].push_back(v);
            int d=bfs(adj,n);
            result.push_back(d);
        } 

        return result;
    }
};