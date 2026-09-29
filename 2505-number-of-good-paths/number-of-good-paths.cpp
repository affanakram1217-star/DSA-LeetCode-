class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x){
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();

        parent.resize(n);
        rank.assign(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        unordered_map<int, vector<int>> adj;

        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //val->{nodes}

        map<int,vector<int>> val_to_nodes;

        for(int i=0;i<n;i++){
            int value=vals[i];
            val_to_nodes[value].push_back(i);
        }

        int result=n;

        vector<bool> is_Active(n,false);

        for(auto& it:val_to_nodes){

            vector<int> nodes=it.second;

            for(int &u:nodes){

                for(int &v: adj[u]){
                    if(is_Active[v]){
                        Union(u,v);
                    }
                }

                is_Active[u]=true;
            }

            vector<int> tumhare_parents;

            for(int& u:nodes){
                int parent_kaun_hai=find(u);
                tumhare_parents.push_back(parent_kaun_hai);
            }

            sort(tumhare_parents.begin(),tumhare_parents.end());

            int sz=tumhare_parents.size();

            for(int j=0;j<sz;j++){
                long long count=0;

                int curr_parent=tumhare_parents[j];

                while(j<sz && tumhare_parents[j]==curr_parent){
                    count++;
                    j++;
                }

                j--;

                int formula=(count*(count-1)/2);
                result+=formula;
            }
        }
        return result;
    }
};