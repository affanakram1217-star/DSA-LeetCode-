class Solution {
public:
    typedef long long LL;

    void DFS(int u,unordered_set<int> &vis,unordered_map<int,vector<int>> &adj){
        vis.insert(u);

        for(int& v:adj[u]){
            if(vis.find(v)==vis.end()){
                DFS(v,vis,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){//ith bomb
            for(int j=0;j<n;j++){//jth bomb
                if(i==j) continue;

                LL x1=bombs[i][0];
                LL y1=bombs[i][1];
                LL r1=bombs[i][2];

                LL x2=bombs[j][0];
                LL y2=bombs[j][1];
                LL r2=bombs[j][2];

                LL d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1); //squared distance
                if(r1*r1>=d){ 
                    adj[i].push_back(j);
                }
            }
        }

        //DFS
        int result=0;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            DFS(i,vis,adj);
            int count=vis.size();
            result=max(result,count);
            vis.clear();//clear the set for the next nodes to be traversed
        }

        return result;
    }
};