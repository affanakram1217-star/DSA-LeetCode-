class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double> result(n,0);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        result[start]=1.0;

        while(!pq.empty()){
            double NodeProb=pq.top().first;
            int CurrNode=pq.top().second;
            pq.pop();
            for(auto temp: adj[CurrNode]){
                double adjProb=temp.second;
                int adjNode=temp.first;

                if(result[adjNode]<NodeProb*adjProb){
                    result[adjNode]=NodeProb*adjProb;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
        return result[end];
    }
};