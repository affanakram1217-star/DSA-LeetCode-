class Solution {
public:
    //DFS
    // void dfs(int index, vector<vector<int>>& stones, vector<bool>&  vis){
    //     vis[index]=true;

    //     for(int i=0;i<stones.size();i++){
    //         int r=stones[index][0];
    //         int c=stones[index][1];

    //         if(!vis[i] && (stones[i][0]==r || stones[i][1]==c)){
    //             dfs(i,stones,vis);
    //         }
    //     }
    // }

    //DSU
    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA=find(a);
        int parB=find(b);

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        // int n=stones.size();
        // vector<bool> vis(n,false);
        // int groups=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,stones,vis);
        //         groups++;
        //     }
        // }
        // return (n-groups);

        int n=stones.size();
        int groups=0;
        par.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unionByRank(i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(par[i]==i){
                groups++;
            }
        }

        return n-groups;
    }
};