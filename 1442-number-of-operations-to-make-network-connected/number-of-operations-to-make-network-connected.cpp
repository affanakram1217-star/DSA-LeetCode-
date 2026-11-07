class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void Union(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(parA==parB){
            return;
        }

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        par.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }
        
        if(connections.size()<n-1){
            return -1;
        }

        int components=n;

        for(auto& edge: connections){
            int u=edge[0];
            int v=edge[1];

            int parU=find(u);
            int parV=find(v);

            if(parU!=parV){
                Union(u,v);
                components--;
            }
        }

        return components-1;    
    }
};