class Solution {
public:
    int m,n;
    void dfs(int i, int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<bool>> &vis, bool& isSub){
        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]!=1 || vis[i][j]){
            return;
        }
        vis[i][j]=true;
        if(grid1[i][j]!=1){
            isSub=false;
        }

        dfs(i - 1, j, grid1, grid2, vis, isSub);
        dfs(i + 1, j, grid1, grid2, vis, isSub);
        dfs(i, j - 1, grid1, grid2, vis, isSub);
        dfs(i, j + 1, grid1, grid2, vis, isSub);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid2.size();
        n=grid2[0].size();
        int count=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    bool isSub=true;
                    dfs(i,j,grid1,grid2,vis,isSub);
                    if(isSub){
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
};