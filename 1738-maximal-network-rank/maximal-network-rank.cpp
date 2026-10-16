class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // //Approach-1
        // unordered_map<int,unordered_set<int>> adj;
        // for(auto& road: roads){
        //     int u=road[0];
        //     int v=road[1];
            
        //     adj[u].insert(v);
        //     adj[v].insert(u);
        // }

        // int maxRank=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int i_rank=adj[i].size();
        //         int j_rank=adj[j].size();
        //         int total=i_rank+j_rank;
        //         if(adj[i].find(j)!=adj[i].end()){
        //             total--;
        //         }
        //         maxRank=max(maxRank,total);
        //     }
        // }

        // return maxRank;
        //Approach-2
        vector<int> degree(n,0);
        vector<vector<bool>> connected(n,vector<bool>(n,false));
        for(auto& road: roads){
            int u=road[0];
            int v=road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v]=true;
            connected[v][u]=true;
        }

        int maxRank=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int i_rank=degree[i];
                int j_rank=degree[j];
                int total=i_rank+j_rank;
                if(connected[i][j]==true){
                    total--;
                }
                maxRank=max(maxRank,total);
            }
        }

        return maxRank;
    }
};