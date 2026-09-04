class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& vis){
        vis[i]=true;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(isConnected, j, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //DFS
        int n=isConnected.size();
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,i,vis);
                count++;
            }
        }
        return count;
    }
};