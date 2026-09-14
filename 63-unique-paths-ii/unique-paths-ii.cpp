class Solution {
public:
    int t[101][101];
    int solve(int i,int j, int m, int n, vector<vector<int>>& obstacleGrid){
        if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int right=solve(i+1,j,m,n,obstacleGrid);
        int down=solve(i,j+1,m,n,obstacleGrid);

        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n,obstacleGrid);
    }
};