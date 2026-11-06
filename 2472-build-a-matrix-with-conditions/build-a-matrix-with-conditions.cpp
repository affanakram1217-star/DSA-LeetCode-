class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& edges, int &n){
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n+1,0);
        for(vector<int>& edge: edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        int count=0;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        vector<int> order;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            order.push_back(u);

            for(int& v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }

        if(count!=n){
            return {};
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