class Solution {
public:
    int N;
    vector<int> count;
    long root_result;
    int dfsRoot(int curr_node, int parent_node, int depth,vector<vector<int>> &adj){
        int total_count=1;
        root_result+=depth;
        for(int &child: adj[curr_node]){
            if(child==parent_node){
                continue;
            }
            total_count+=dfsRoot(child, curr_node, depth+1, adj);
        }
        count[curr_node]=total_count;

        return total_count;
    }
    void dfs(int parent_node, int prev_node, vector<vector<int>> &adj, vector<int>& result){

        for(int &child: adj[parent_node]){
            if(child==prev_node) continue;
            result[child]=result[parent_node]-count[child]+(N-count[child]);
            dfs(child, parent_node, adj,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        N=n;
        count.resize(n,0);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root_result=0;

        dfsRoot(0,-1,0,adj);

        vector<int> result(n,0);
        result[0]=root_result;

        dfs(0,-1,adj,result);

        return result;
    }
};