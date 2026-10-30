class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    void Union(int a, int b){
        parent[b]=a;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }

        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            int par_u=find(u);
            int par_v=find(v);
            if(par_u !=par_v){
                Union(par_u,par_v);
                cost[par_u]&=cost[par_v];
            }
            cost[par_u]&=wt;
        }

        vector<int> result;
        for(auto& q:query){
            int s=q[0];
            int t=q[1];

            int par_s=find(s);
            int par_t=find(t);

            if(s==t){
                result.push_back(0);
            }else if(par_s!=par_t){
                result.push_back(-1);
            }else{
                result.push_back(cost[par_s]);
            }
        }

        return result;
    }
};