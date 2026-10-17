class Solution {
public:
    int N;
    class UnionFind{
    public:
        vector<int> par;
        vector<int> rank;

        UnionFind(int n){
            rank.resize(n);
            par.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }

        int find(int x){
            if(par[x]==x){
                return x;
            }
            return par[x]=find(par[x]);
        }

        bool Union(int a, int b){
            int parA=find(a);
            int parB=find(b);
            if(parA==parB){
                return false;
            }

            if(rank[parA]==rank[parB]){
                par[parB]=parA;
                rank[parA]++;
            }else if(rank[parA]>rank[parB]){
                par[parB]=parA;
            }else{
                par[parA]=parB;
            }

            return true;
        }

    };
    int kruskal(vector<vector<int>>& edges,int skip_edge, int add_edge){
        int mst_wt=0;
        UnionFind uf(N);
        if(add_edge!=-1){
            uf.Union(edges[add_edge][0],edges[add_edge][1]);
            mst_wt+=edges[add_edge][2];
        }

        for(int i=0;i<edges.size();i++){
            if(i==skip_edge) continue;

            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            int parU=uf.find(u);
            int parV=uf.find(v);

            if(parU!=parV){
                uf.Union(u,v);
                mst_wt+=wt;
            }
        }
        for(int i=0;i<N;i++){
            if(uf.find(i)!=uf.find(0)){
                return INT_MAX;
            }
        }

        return mst_wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }

        auto lambda=[&](vector<int>& vec1,vector<int>& vec2){
            return vec1[2]<vec2[2];
        };

        sort(edges.begin(),edges.end(),lambda);

        int MST_weight=kruskal(edges,-1,-1);

        vector<int> criticalPts;
        vector<int> PseudoCritical;

        for(int i=0;i<edges.size();i++){
            if(kruskal(edges,i,-1)>MST_weight){
                criticalPts.push_back(edges[i][3]);
            }else if(kruskal(edges,-1,i)==MST_weight){
                PseudoCritical.push_back(edges[i][3]);
            }
        }

        return {criticalPts,PseudoCritical};
    }
};