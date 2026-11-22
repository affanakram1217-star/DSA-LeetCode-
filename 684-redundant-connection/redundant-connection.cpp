class DSU{
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(parA==parB){
            return;
        }

        if(rank[parA]==rank[parB]){
            parent[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }else{
            parent[parA]=parB;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);

        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];

            if(dsu.find(u)==dsu.find(v)){
                return edge;
            }

            dsu.Union(u,v);
        }

        return {};
    }
};