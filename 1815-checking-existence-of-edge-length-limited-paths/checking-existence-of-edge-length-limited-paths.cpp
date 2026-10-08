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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        par.resize(n);
        rank.assign(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }

        //queries me uska original index store kr lena h
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        //sort the edgeList and queries on the basis of distance in asc order

        auto lambda=[&](vector<int>&v1, vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(edgeList.begin(),edgeList.end(),lambda);
        sort(queries.begin(),queries.end(),lambda);

        //DSU +logic
        int j=0; //pointer that points to edges
        vector<bool> result(queries.size());

        for(int i=0;i<queries.size();i++){
            vector<int> query=queries[i];
            int u=query[0];
            int v=query[1];
            int wt=query[2];
            int Org_idx=query[3];

            while(j<edgeList.size() && edgeList[j][2]<wt ){
                Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }

            if(find(u)==find(v)){//dono ka parent same h to ek group me h and condition satisfy kar rha
                result[Org_idx]=true;
            }else{
                result[Org_idx]=false;
            } 
        }

        return result;

    }
};