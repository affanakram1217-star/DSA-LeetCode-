class Solution {
public:
    int m;
    int n;
    int peri;
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=m ||j<0 ||j>=n || grid[i][j]==0){
            peri++;
            return;
        }
        if(grid[i][j]==-1){
            return;
        }

        grid[i][j]=-1;//mark visited
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        //same approach as number of islands 200
        m=grid.size();
        n=grid[0].size();
        peri=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    return peri;
                }
            }
        }
        return -1;
    }
};