class Solution {
public:
    int m,n;
    int maxArea;
    int dfs(int i, int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1 || vis[i][j]){
            return 0 ;
        }
        vis[i][j]=true;
        
        return 1+dfs(i+1,j,grid,vis)
        +dfs(i-1,j,grid,vis)
        +dfs(i,j-1,grid,vis)
        +dfs(i,j+1,grid,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        maxArea=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    maxArea=max(maxArea,dfs(i,j,grid,vis));
                    
                }
            }
        }
        return maxArea;
    }
};