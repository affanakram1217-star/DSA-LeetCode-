class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;
    vector<ll> dijkstra(int src,unordered_map<int,vector<pair<int,int>>> &adj,int n){
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<ll> result(n,LLONG_MAX);
        result[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            ll currWt=pq.top().first;
            int currNode=pq.top().second; 
            pq.pop();

            for(auto ngbr: adj[currNode]){
                int adjNode=ngbr.first;
                ll nextWt=ngbr.second;

                if(currWt+nextWt<result[adjNode]){
                    result[adjNode]=currWt+nextWt;
                    pq.push({currWt+nextWt,adjNode});
                }
            }
        }

        return result;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E=edges.size();

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<ll> fromSrc=dijkstra(0,adj,n);
        vector<ll> fromDest=dijkstra(n-1,adj,n);

        vector<bool> result(E,false);

        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            ll distFromSrc=fromSrc[u];
            ll distFromDest=fromDest[v];

            if(distFromSrc!=LLONG_MAX && distFromDest!=LLONG_MAX && distFromSrc+w+distFromDest==fromSrc[n-1]){
                result[i]=true;
            }

            distFromSrc=fromSrc[v];
            distFromDest=fromDest[u];

            if(distFromSrc!=LLONG_MAX && distFromDest!=LLONG_MAX && distFromSrc+w+distFromDest==fromSrc[n-1]){
                result[i]=true;
            }

        }

        return result;
    }
};