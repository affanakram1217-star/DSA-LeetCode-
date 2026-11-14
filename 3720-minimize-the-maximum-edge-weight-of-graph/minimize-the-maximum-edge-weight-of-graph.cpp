class Solution {
public:
    typedef pair<int,int> P;

    bool canAllReachZero(int n, int mid, unordered_map<int,vector<P>> &adj){
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto& p:adj[u]){
                int v=p.first;
                int wt=p.second;

                if(wt<=mid && !vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int,vector<P>> adj;
        int maxWt=0;

        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            adj[v].push_back({u,w});
            maxWt=max(maxWt,w);
        }

        int result=INT_MAX;
        int l=0;
        int r=maxWt;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(canAllReachZero(n,mid,adj)==true){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result==INT_MAX?-1:result;
    }
};