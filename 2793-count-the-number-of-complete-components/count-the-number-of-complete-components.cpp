class DSU{
public:
    vector<int> par;
    vector<int> size;

    DSU(int n){
        par.resize(n);
        size.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }

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
            return ;
        }

        if(size[parA]==size[parB]){
            par[parB]=parA;
            size[parA]+=size[parB];
        }else if(size[parA]>size[parB]){
            par[parB]=parA;
            size[parA]+=size[parB];
        }else{
            par[parA]=parB;
            size[parB]+=size[parA];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto& edge : edges){
            int u=edge[0];
            int v=edge[1];

            dsu.Union(u,v);
        }

        unordered_map<int,int> mp; //root node , no of edges

        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int root=dsu.find(u);
            mp[root]++;
        }
        int result=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i){
                int e=mp[i];
                int v=dsu.size[i];

                if((v*(v-1)/2)==e){
                    result++;
                }
            }
        }

        return result;
    }
};