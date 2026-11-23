class Solution {
public:
    bool isBipartite(unordered_map<int,vector<int>> &adj,int curr, vector<int>& colors, int currColor){
        colors[curr]=currColor;

        for(int &ngbr: adj[curr]){
            if(colors[ngbr]==colors[curr]){
                return false;
            }

            if(colors[ngbr]==-1){
                if(isBipartite(adj,ngbr,colors,1-currColor)==false){
                    return false;
                }
            }
        }

        return true;
    }

    int bfs(unordered_map<int,vector<int>> &adj, int curr, int n){
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(curr);
        vis[curr]=true;

        int level=1; //max groups in a component
        while(!q.empty()){

            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();

                for(int &ngbr: adj[curr]){
                    if(vis[ngbr]){
                        continue;
                    }
                    q.push(ngbr);
                    vis[ngbr]=true;
                }
            }
            level++; //1 extra will be incremented in the last loop
        }

        return level -1;
    }

    int getMaxFromEachComp(unordered_map<int,vector<int>> &adj, int curr, vector<bool>& vis, vector<int>& levels){
        int maxGrp=levels[curr];
        vis[curr]=true;

        for(int& ngbr: adj[curr]){
            if(!vis[ngbr]){
                maxGrp=max(maxGrp, getMaxFromEachComp(adj,ngbr,vis, levels));
            }
        }

        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge:edges){
            int u=edge[0]-1; //converting to 0-based indexing
            int v=edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bipartite check
        vector<int> colors(n,-1);
        for(int node=0;node<n;node++){
            if(colors[node]==-1){
                if(isBipartite(adj,node,colors,1)==false){
                    return -1;
                }
            }
        }

        vector<int> levels(n,0);
        for(int node=0;node<n;node++){
            levels[node]=bfs(adj,node,n);
        }

        int maxGroupEachComp=0;
        vector<bool> vis(n,false);
        for(int node=0;node<n;node++){
            if(!vis[node]){
                maxGroupEachComp+=getMaxFromEachComp(adj,node,vis,levels);
            }
        }

        return maxGroupEachComp;
    }
};