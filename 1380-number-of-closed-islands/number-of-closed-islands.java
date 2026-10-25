class Solution {
    int m;
    int n;

    void dfs(int i, int j, int[][] grid){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return;
        }

        grid[i][j]=1; //mark visited

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    public int closedIsland(int[][] grid) {
        //flood fill Algo se
        m=grid.length;
        n=grid[0].length;

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==0){
                    dfs(i,j,grid);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    ans++;
                }
                
            }
        }

        return ans;
    }
}