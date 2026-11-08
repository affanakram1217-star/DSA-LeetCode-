class Solution {
public:
    void dijkstra(int S,unordered_map<int,vector<pair<int,int>>> &adj, vector<int>& result, int n){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto& P: adj[node]){
                int adjNode=P.first;
                int dist=P.second;

                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
    }

    int findTheResultCity(int n,  vector<vector<int>> &SPM, int D){
        int resultCity=-1;
        int leastCityReachcnt=INT_MAX;

        for(int i=0;i<n;i++){
            int currCityCnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && SPM[i][j]<=D){
                    currCityCnt++;
                }
            }

            if(currCityCnt<=leastCityReachcnt){
                leastCityReachcnt=currCityCnt;
                resultCity=i;
            }
        }

        return resultCity;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Approach 1->Dijkstra Algo
        vector<vector<int>> SPM(n,vector<int>(n,1e9+7));

        for(int i=0;i<n;i++){
            SPM[i][i]=0;
        }

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        //calculating shortest path from each node
        for(int i=0;i<n;i++){
            dijkstra(i,adj,SPM[i],n);
        }

        return findTheResultCity(n,SPM,distanceThreshold);
    }
};