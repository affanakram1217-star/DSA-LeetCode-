class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>> &adj,vector<int>& vis, stack<int>& st,bool& cycle){
        vis[u]=1;

        for(int& v: adj[u]){
            if(vis[v]==0){
                dfs(v,adj,vis,st,cycle);
            }else if(vis[v]==1){
                cycle=true;
                return;
            }
        }

        vis[u]=2;
        st.push(u);
    }
    vector<int> topoSort(vector<vector<int>>& edges, int &n){
        unordered_map<int,vector<int>> adj;
        for(vector<int>& edge: edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(n+1,0);
        stack<int> st;
        vector<int> order;
        bool cycle=false;

        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,st,cycle);
                if(cycle==true){
                    return {};
                }
            }
        }

        while(!st.empty()){
            int u=st.top();
            st.pop();
            order.push_back(u);
        }

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow=topoSort(rowConditions, k);
        vector<int> topoCol=topoSort(colConditions, k);

        vector<vector<int>> matrix(k,vector<int>(k,0));

        if(topoRow.empty() || topoCol.empty()){
            return {};
        }

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(topoRow[i]==topoCol[j]){
                    matrix[i][j]=topoRow[i];
                }
            }
        }

        return matrix;
    }
};