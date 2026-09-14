class Solution {
public:
    // int t[101][101];
    // int solve(int i,int j, int m, int n, vector<vector<int>>& obstacleGrid){
    //     if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
    //         return 0;
    //     }
    //     if(i==m-1 && j==n-1){
    //         return 1;
    //     }
    //     if(t[i][j]!=-1){
    //         return t[i][j];
    //     }
    //     int right=solve(i+1,j,m,n,obstacleGrid);
    //     int down=solve(i,j+1,m,n,obstacleGrid);

    //     return t[i][j]=right+down;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        // int m=obstacleGrid.size();
        // int n=obstacleGrid[0].size();
        // memset(t,-1,sizeof(t));
        // return solve(0,0,m,n,obstacleGrid);

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> t(m,vector<int>(n));

        //filling first row
        for(int col=0;col<n;col++){
            if(col>=1 && grid[0][col-1]==1){
                t[0][col]=0;
                grid[0][col]=1;
            }else if(grid[0][col]==1){
                t[0][col]=0;
            }else{
                t[0][col]=1;
            }
        }

        //filling first column
        for(int row=0;row<m;row++){
            if(row>=1 && grid[row-1][0]==1){
                t[row][0]=0;
                grid[row][0]=1;
            }else if(grid[row][0]==1){
                t[row][0]=0;
            }else{
                t[row][0]=1;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    t[i][j]=0;
                }else{
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }

        return t[m-1][n-1];
    }
};