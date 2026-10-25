class Solution {
public:
    int m;
    int n;
    bool dfs(int i, int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }

        //water hai ya already visited h
        if(grid[i][j]==1 || vis[i][j]){
            return true;
        }
        vis[i][j]=true;
        
        bool left_side=dfs(i,j-1,vis,grid);
        bool right_side=dfs(i,j+1,vis,grid);
        bool up=dfs(i-1,j,vis,grid);
        bool down=dfs(i+1,j,vis,grid);

        return left_side && right_side && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int ans=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    if(dfs(i,j,vis,grid)){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};