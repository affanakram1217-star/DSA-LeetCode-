class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> bobMap;

    int aliceIncome;

    bool DFSBob(int curr, int time, vector<bool>& vis){
        vis[curr]=true;
        bobMap[curr]=time;

        if(curr==0){
            return true;
        }

        for(auto& ngbr: adj[curr]){
            if(!vis[ngbr]){
                if(DFSBob(ngbr,time+1,vis)){
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        aliceIncome=INT_MIN;

        for(vector<int> edge: edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time=0;
        vector<bool> vis(n,false);
        DFSBob(bob,time,vis);

        int income=0;
        vis.assign(n,false);
        queue<vector<int>> q;
        q.push({0,0,0});
        
        while(!q.empty()){
            int node=q.front()[0];
            int t=q.front()[1];
            int income=q.front()[2];
            q.pop();

            if(bobMap.find(node)==bobMap.end() || t<bobMap[node]){
                income+=amount[node];
            }else if(t==bobMap[node]){
                income+=amount[node]/2;
            }

            if(adj[node].size()==1 && node!=0){
                aliceIncome=max(aliceIncome,income);
            }

            for(auto& ngbr:adj[node]){
                if(!vis[ngbr]){
                    q.push({ngbr,t+1,income});
                }
            }

            vis[node]=true;
        }
        return aliceIncome;

    }
};