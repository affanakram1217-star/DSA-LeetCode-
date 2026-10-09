class DSU{
public:
    vector<int> par;
    vector<int> rank;
    int components;

    DSU(int n){
        par.resize(n+1);
        rank.assign(n+1,0);
        components=n;

        for(int i=0;i<n+1;i++){
            par[i]=i;
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

        if(parA==parB) return;

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }

        components--;
    }

    bool isSingleComponent(){
        return components==1;
    }
};

class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda=[&](vector<int>& vec1,vector<int> vec2){
            return vec1[0]>vec2[0];
        };
        sort(edges.begin(),edges.end(),lambda);

        int edgeCount=0;

        for(auto& vec: edges){
            int type=vec[0];
            int u=vec[1];
            int v=vec[2];

            if(type==3){
                bool addEdgekara_ya_nahi=false;
                //Alice
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    addEdgekara_ya_nahi=true;
                }

                //Bob
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    addEdgekara_ya_nahi=true;
                }

                if(addEdgekara_ya_nahi==true){
                    edgeCount++;
                }
            }

            else if(type==2){
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            }

            else {
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }

        if(Alice.isSingleComponent()==true && Bob.isSingleComponent()==true){
            return edges.size()-edgeCount;
        }

        return -1;
    }
};