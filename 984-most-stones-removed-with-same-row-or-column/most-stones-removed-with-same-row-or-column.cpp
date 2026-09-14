class Solution {
public:
    //DFS
    void dfs(int index, vector<vector<int>>& stones, vector<bool>&  vis){
        vis[index]=true;

        for(int i=0;i<stones.size();i++){
            int r=stones[index][0];
            int c=stones[index][1];

            if(!vis[i] && (stones[i][0]==r || stones[i][1]==c)){
                dfs(i,stones,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> vis(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,vis);
                groups++;
            }
        }
        return (n-groups);
    }
};