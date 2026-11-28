class Solution {
public:
    typedef pair<long long, int> P;
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& road: roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<long long> result(n,LLONG_MAX);
        vector<int> countPaths(n,0);

        result[0]=0;
        countPaths[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            long long currTime=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();

            for(auto& vec:adj[currNode]){
                int ngbr=vec.first;
                int time=vec.second;

                if(currTime+time<result[ngbr]){
                    result[ngbr]=currTime+time;
                    pq.push({currTime+time,ngbr});
                    countPaths[ngbr]=countPaths[currNode];
                }else if(currTime+time==result[ngbr]){
                    countPaths[ngbr]=(countPaths[ngbr]+countPaths[currNode])%MOD;
                }
            }
        }
        return countPaths[n-1];
    }
};